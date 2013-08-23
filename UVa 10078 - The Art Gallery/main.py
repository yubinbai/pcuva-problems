import sys
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])


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
    return 0  # P->Q->R is a straight line, i.e. P, Q, R are collinear

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    pts = []
    for i in range(N):
        row = map(int, raw_input().split())
        pts.append(Point(row[0], row[1]))
    prev = turn(pts[0], pts[1], pts[2])
    flag = True
    for i in range(3, N):
        curr = turn(pts[i - 2], pts[i - 1], pts[i])
        if curr != prev:
            flag = False
            break
    if flag:
        print 'No'
    else:
        print 'Yes'
