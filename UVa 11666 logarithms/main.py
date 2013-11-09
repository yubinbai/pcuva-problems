import sys
import math

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    l = math.log(n)
    print '%d %.8f' % (int(l) + 1, 1 - n / math.exp(int(l) + 1))
