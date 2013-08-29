from collections import namedtuple
from itertools import combinations
import sys

Point = namedtuple('Point', ['x', 'y'])


def area2(p0, p1, p2):
    return p0.x * p1.y + p2.x * p0.y + p1.x * p2.y \
        - p2.x * p1.y - p0.x * p2.y - p1.x * p0.y


sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    pts = {}
    for itertest in range(N):
        line = raw_input().split()
        pts[line[0]] = Point(int(line[1]), int(line[2]))
    # print pts
    names = pts.keys()
    maxA = 0
    maxName = ''
    for a, b, c in combinations(names, 3):
        abcA = area2(pts[a], pts[b], pts[c])
        flag = True
        for o in names:
            if o != a and o != b and o != c:
                oabA = area2(pts[o], pts[a], pts[b])
                obcA = area2(pts[o], pts[b], pts[c])
                ocaA = area2(pts[o], pts[c], pts[a])
                if abs(abcA) == abs(oabA) + abs(obcA) + abs(ocaA):
                    # print o, a, b, c
                    flag = False
                    break
        # print abcA
        if flag and abs(abcA) > maxA:
            maxA = abs(abcA)
            maxName = [a, b, c]
    maxName.sort()
    print ''.join(maxName)
