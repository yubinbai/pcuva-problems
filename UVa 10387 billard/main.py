import sys
from math import *

sys.stdin = open('input.txt')
while True:
    a, b, s, m, n = map(float, raw_input().split())
    if not any([a, b, s, m, n]):
        break
    # print a,b,s,m,n
    L = hypot(m * a, n * b)
    angle = acos(m * a / L)
    print '%.2f %.2f' % (angle * 180 / pi, L / s)
