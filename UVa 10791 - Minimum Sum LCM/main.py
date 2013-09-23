import sys
from math import sqrt
from collections import Counter


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    while i <= sqrt(n):
        if n % i == 0:
            l = primeFactors(n / i)
            l.append(i)
            return l
        i += 1
    return [n]  # n is prime

sys.stdin = open('input.txt')
case = 1
while True:
    N = int(input())
    if not N:
        break
    c = Counter(primeFactors(N))
    if len(c) == 1:
        total = N + 1
    else:
        total = 0
        for k, v in c.items():
            total += k ** v

    print 'Case %d: %d' % (case, total)
    case += 1
