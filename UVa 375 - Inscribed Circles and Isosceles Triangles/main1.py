import sys
from math import *

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    B, H = map(float, raw_input().split())
    L = hypot(B / 2, H)
    k = B / (B + 2 * L)
    p = H
    r = p * k
    while r >= 0.000001:
        p -= 2 * r
        r = p * k
    print '%.6f' % (pi * (H - p))
