from collections import namedtuple
from itertools import combinations
from random import randrange
import sys

Point = namedtuple('Point', ['x', 'y'])


class Line:

    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2


def turn(p, q, r):
    '''
    application of cross product
    '''
    x1, y1 = q.x - p.x, q.y - p.y  # vector p->q
    x2, y2 = r.x - q.x, r.y - q.y  # vector q->r

    result = x1 * y2 - x2 * y1  # 1 cross 2
    if result < 0:
        return 1  # P->Q->R is a right turn
    if result > 0:
        return -1  # P->Q->R is a left turn
    return 0  # P->Q->R is a straight Line, i.e. P, Q, R are collinear


def linesIntersect(line1, line2):
    return ((turn(line1.p1, line1.p2, line2.p1) * turn(line1.p1, line1.p2, line2.p2)) < 0) \
        and \
        ((turn(line2.p1, line2.p2, line1.p1) * turn(line2.p1, line2.p2, line1.p2)) < 0)


sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    N = int(input())
    lines = []
    for i in range(N):
        row = map(int, raw_input().split())
        line1 = Line(Point(row[0], row[1]), Point(row[2], row[3]))
        lines.append(line1)

    total = len(lines)
    for line1, line2 in combinations(lines, 2):
        if linesIntersect(line1, line2):
            total += 2
    print(total)
