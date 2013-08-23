import sys
from itertools import combinations
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
numTest = int(input())
raw_input()
for itertest in range(numTest):
    points = []
    while True:
        try:
            x, y = map(int, raw_input().split())
        except:
            break
        points.append(Point(x, y))
    result = 0
    N = len(points)
    for i in range(N):
        for j in range(i + 1, N):
            counter = 2
            for k in range(N):
                if k != i and k != j:
                    if not turn(points[i], points[j], points[k]):
                        counter += 1
            result = max(result, counter)
    print result
