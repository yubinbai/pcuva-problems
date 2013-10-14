import collections
import sys
import math
import itertools
MAXN = 0xFFFFFFF
N = 100010
Point = collections.namedtuple('Point', ['x', 'y'])


def dist(a, b):
    return math.hypot(a.x - b.x, a.y - b.y)


def closestPair(left, right):
    d = MAXN
    if (left == right):
        return d
    if (left + 1 == right):
        return dist(p[left], p[right])
    mid = (left + right) >> 1
    d1 = closestPair(left, mid)
    d2 = closestPair(mid + 1, right)
    d = min(d1, d2)

    midPoints = []
    for i in range(left, right + 1):
        if (abs(p[mid].x - p[i].x) <= d):
            midPoints.append(p[i])
    for p1, p2 in itertools.combinations(midPoints, 2):
        if abs(p1.y - p2.y) < d:
            d = min(d, dist(p1, p2))
    return d

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    while True:
        n = int(input())
        if not n:
            break
        p = []
        for i in range(n):
            p.append(Point(*map(int, raw_input().split())))
        p.sort()
        MIN = closestPair(0, n - 1)
        if (MIN - 10000 > 1e-9):
            print("INFINITY")
        else:
            print("%.4lf" % MIN)
