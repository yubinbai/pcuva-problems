import sys
import math


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    seq = [int(input()) for _ in range(n)]
    count = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if gcd(seq[i], seq[j]) == 1:
                count += 1
    if count == 0:
        print 'No estimate for this data set.'
    else:
        print '%.6f' % math.sqrt(6.0 / (count * 1.0 / (n * (n - 1) / 2)))
