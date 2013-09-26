import sys
import math

sys.stdin = open('input.txt')
numTest = int(input())
for x in range(numTest):
    raw_input()
    n = int(input())
    temp = n >> ((len(bin(n)) - 2) >> 1)
    while True:
        result = (temp + (n / temp)) >> 1
        if temp != result:
            temp = result
        else:
            break
    print result
