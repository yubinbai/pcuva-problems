from collections import namedtuple
import sys
from math import sqrt

Point = namedtuple('Point', ['x', 'y'])


def segPartLen(p, q, yPrime):
    '''
    part of segment p-q
    use y coordinate for ratio calc
    p is higher than q
    '''
    return sqrt((p.x - q.x) ** 2 + (p.y - q.y) ** 2) *\
        (p.y - yPrime) / (p.y - q.y)


def solve(par):
    N, points = par
    points.sort()
    total = 0.0
    p = points[-2]
    q = points[-1]
    total += segPartLen(p, q, q.y)
    for i in range(N - 3, -1, -1):
        if points[i].y > p.y:
            yPrime = p.y
            p, q = points[i], points[i + 1]
            total += segPartLen(p, q, yPrime)
    return '%.2f' % total

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    numTest = int(input())
    for itertest in range(numTest):
        N = int(input())
        points = []
        for i in range(N):
            row = map(float, raw_input().split())
            points.append(Point(row[0], row[1]))
        print(solve((N, points)))
