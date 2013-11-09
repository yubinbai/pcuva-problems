from collections import namedtuple
from math import atan2
from random import randrange
import sys

Point = namedtuple('Point', ['x', 'y'])


class Line:

    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def linesIntersect(self, other):
        return ((ccw(self.p1, self.p2, other.p1) * ccw(self.p1, self.p2, other.p2)) <= 0) \
            and ((ccw(other.p1, other.p2, self.p1) * ccw(other.p1, other.p2, self.p2)) <= 0)


def ccw(p, q, r):
    '''
    CCW (Counter Clockwise) Test, p,q,r are points
    '''
    def turn(p, q, r):
        # application of cross product
        result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x)
        if result < 0:
            # P->Q->R is a right turn
            return -1
        if result > 0:
            # P->Q->R is a left turn
            return 1
        # P->Q->R is a straight line, i.e. P, Q, R are collinear
        return 0
    return (turn(p, q, r) > 0)


def grahamSearch(polygon):
    def pivotAngle(a):
        d1x = a.x - pivot.x
        d1y = a.y - pivot.y
        return atan2(d1y, d1x)

    # first, find P0 = point with lowest Y and if tie: rightmost X
    p0 = 0
    N = len(polygon)
    for i in range(N):
        if polygon[i].y < polygon[p0].y or\
                (polygon[i].y == polygon[p0].y and polygon[i].x > polygon[p0].x):
            p0 = i
    polygon[0], polygon[p0] = polygon[p0], polygon[0]
    # second, sort points by angle w.r.t. P0, skipping Polygon [0]
    pivot = polygon[0]  # use this global variable as reference
    polygon = [polygon[0]] + sorted(polygon[1:], key=pivotAngle)

    # third, the ccw tests
    S = [polygon[N - 1], polygon[0]]  # put two starting vertices into stack S
    i = 1  # and start checking the rest
    while (i < N):  # note: N must be >= 3 for this method to work
        now = S[-1]
        prev = S[-2]
        # if these 3 points make a left turn
        if (ccw(prev, now, polygon[i])):
            S.append(polygon[i])
            i += 1
        else:
            S.pop()
    # S.pop()  # the last point is a duplicate of first point
    return S


def isInside(pt, poly):
    for i in range(1, len(poly)):
        if not ccw(pt, poly[i - 1], poly[i]):
            return False
    return True


def polyArea(poly):
    return 0.5 * sum([poly[i - 1].x * poly[i].y - poly[i].x * poly[i - 1].y
                      for i in range(1, len(poly))])

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    hulls = []
    while True:
        pts = []
        n = int(input())
        if n == -1:
            break
        for _ in range(n):
            pts.append(Point(*map(float, raw_input().strip().split())))
        h = grahamSearch(pts)
        hulls.append(list(h))
    occupiedHulls = set()
    while True:
        try:
            x, y = map(float, raw_input().strip().split())
        except:
            break
        for i in range(len(hulls)):
            if isInside(Point(x, y), hulls[i]):
                occupiedHulls.add(i)
    print '%.2f' % sum([polyArea(hulls[h]) for h in occupiedHulls])
