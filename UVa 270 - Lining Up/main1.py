import sys
from itertools import combinations
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])


def turn(v1, v2):
    result = v1.x * v2.y - v2.x * v1.y  # 1 cross 2
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
            v1 = Point(points[j].x - points[i].x,
                       points[j].y - points[i].y)
            counter = 2
            for k in range(j + 1, N):
                v2 = Point(points[k].x - points[j].x,
                           points[k].y - points[j].y)
                if not turn(v1, v2):
                    counter += 1
            result = max(result, counter)
    print result
