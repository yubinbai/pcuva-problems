import sys
from math import sqrt


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
while True:
    N = int(input())
    if N == -1:
        break
    factors = primeFactors(N)
    factors.sort()
    print '\n'.join(str(e) for e in factors)
    print 
