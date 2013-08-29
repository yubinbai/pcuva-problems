import sys
from bisect import *

sys.stdin = open('input.txt')
sums = [0, 1]
for i in range(2, 100000):
    sums.append(sums[-1] + i)
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    n = int(input())
    pos = bisect_right(sums, abs(n))
    print pos
