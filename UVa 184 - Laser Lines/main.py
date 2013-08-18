'''
Created on Jul 29, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
import sys
from numpypy import *
from itertools import *
from multiprocessing.pool import Pool
from heapq import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    points = par
    lines = {}
    for p1, p2 in combinations(points, 2):
        if p1[0] != p2[0]:
            m = 1.0 * (p1[1] - p2[1]) / (p1[0] - p2[0])
            c = p1[1] - m * p1[0]
            if (m, c) in lines:
                lines[(m, c)].add(p1)
                lines[(m, c)].add(p2)
            else:
                lines[(m, c)] = set([p1, p2])
        else:
            if 'flat' in lines:
                lines['flat'].add(p1)
                lines['flat'].add(p2)
            else:
                lines['flat'] = set([p1, p2])
    result = []
    for k, v in lines.items():
        if len(v) > 2:
            result.append(' '.join(str(e) for e in v))
    if result:
        return '\n'.join(result)
    else:
        return 'No lines'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        inList = []
        while True:
            try:
                line = raw_input().strip()
            except:
                break
            inList += map(int, line.split())
        it = iter(inList)
        points = []
        while True:
            try:
                a, b = it.next(), it.next()
            except:
                break
            if a == 0 and b == 0:
                if points:
                    self.numOfTests += 1
                self.input.append((list(points)))
                points = []
            else:
                points.append((a, b))

    def __init__(self):
        sys.stdin = open('input.txt')
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
            self.fOut.write("Case#%d\n %s\n" % (test + 1, self.results[test]))
        sys.stdin.close()
        self.fOut.close()
if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
