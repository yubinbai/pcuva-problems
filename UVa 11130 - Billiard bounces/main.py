import sys
from math import *


def solve(a, b, v, A, s):
    x0, y0 = a / 2.0, b / 2.0
    rad = A / 180.0 * pi
    x1 = x0 + v * s / 2.0 * cos(rad)
    y1 = y0 + v * s / 2.0 * sin(rad)
    return '%d %d' % (x1 // a, y1 // b)

sys.stdin = open('input.txt')
for line in sys.stdin:
    a, b, v, A, s = map(float, line.split())
    if a == 0:
        break
    print(solve(a, b, v, A, s))
