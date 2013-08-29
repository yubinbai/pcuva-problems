# ln n! = n ln(n) - n + O(ln(n))
# stirling's formula
from bisect import bisect_left
from math import log
import sys

sys.stdin = open('input.txt')
table = map(lambda n: n * log(n) - n, range(1, 500000))
while True:
    N = int(input())
    if not N:
        break
    bits = 4 * 1 << (N // 10 - 196)
    # print bits
    a1 = log(1 << (bits))
    print bisect_left(table, a1) - 1
