import sys
from math import *

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    B, H = map(float, raw_input().split())
    sumR = 0
    angle = atan(H / (B / 2.0))
    while True:
        r = B / 2.0 * tan(angle / 2.0)
        if r >= 0.000001:
            sumR += r
            H -= 2 * r
            B = H / tan(angle)
        else:
            break
    # print 2 * pi * sumR
    print '%.6f' % (2 * pi * sumR)
