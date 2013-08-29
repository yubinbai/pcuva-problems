def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

import sys

sys.stdin = open('input.txt')
while True:
    try:
        N, M = map(int, raw_input().split())
    except:
        break
    if gcd(N, M) == 1:
        print 'Good Choice'
    else:
        print 'Bad Choice'
