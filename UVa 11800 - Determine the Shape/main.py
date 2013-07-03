'''
Created on Jun 29, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from math import acos, sqrt
parallelSolve = False
INF = 1 << 30


class Point(object):

    """2d Point class with some vector operations """

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dx(self, other):
        return other.x - self.x

    def dy(self, other):
        return other.y - self.y

    def dist2(self, other):
        return self.dx(other) ** 2 + self.dy(other) ** 2

    @property
    def mod(self):
        return sqrt(self.x ** 2 + self.y ** 2)

    def angle(self, other):
        return acos(self.dot(other) / self.mod / other.mod)

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __lt__(self, other):
        return self.x < other.x or (self.x == other.x and self.y < other.y)


def solve(par):

    def ccw(a, b):
        return (a - pivot).cross(b - pivot) > 0

    pts = par
    pts = [Point(e[0], e[1]) for e in pts]
    pivot = min(pts)
    idx = pts.index(pivot)
    pts.pop(idx)
    # sort using ccw
    if ccw(pts[0], pts[1]):
        pts[0], pts[1] = pts[1], pts[0]
    if ccw(pts[0], pts[2]):
        pts[0], pts[2] = pts[2], pts[0]
    if ccw(pts[1], pts[2]):
        pts[1], pts[2] = pts[2], pts[1]
    pts.append(pivot)

    pts = pts * 2
    angles = set()
    for i in range(4):
        a, b, c = pts[i:i + 3]
        angles.add(180.0 / acos(-1) * (b - a).angle(c - b))

    dist = set()
    edges = []
    for i in range(4):
        a, b = pts[i:i + 2]
        dist.add(a.dist2(b))
        edges.append(a - b)

    a = len(angles)
    d = len(dist)
    if a == 1 and d == 1:
        return 'Square'
    if a == 1 and d == 2:
        return 'Rectangle'
    if d == 1 and a != 1:
        return 'Rhombus'
    if d == 2 and a != 1:
        return 'Parallelogram'
    for e in edges:
        for e2 in edges:
            if e != e2 and e.cross(e2) == 0:
                return 'Trapezium'
    return 'Ordinary Quadrilateral'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for test in range(self.numOfTests):
            pts = []
            for i in range(4):
                x, y = map(int, self.fIn.readline().strip().split())
                pts.append([x, y])
            self.input.append((pts))

    def __init__(self):
        self.fIn = open('input.txt')
        self.fOut = open('output.txt', 'w')
        self.results = []

    def parallel(self):
        self.getInput()
        p = Pool(4)
        millis1 = int(round(time.time() * 1000))
        self.results = p.map(solve, self.input)
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def sequential(self):
        self.getInput()
        millis1 = int(round(time.time() * 1000))
        for i in self.input:
            self.results.append(solve(i))
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def makeOutput(self):
        for test in range(self.numOfTests):
            self.fOut.write("Case #%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
