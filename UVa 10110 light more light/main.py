from math import sqrt
import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    s = sqrt(N)
    if s ** 2 == N:
        print 'yes'
    else:
        print 'no'
