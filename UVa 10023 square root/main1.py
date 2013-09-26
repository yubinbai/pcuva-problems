import sys
import math

sys.stdin = open('input.txt')
numTest = int(input())
for x in range(numTest):
    raw_input()
    n = int(input())
    root = 1
    while root ** 2 != n:
        # root += (n - root ** 2) / (2 * root)
        root += (n >> 1) / root - (root >> 1)
    # print root
