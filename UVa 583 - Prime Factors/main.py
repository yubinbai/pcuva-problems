import sys
import math


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    while i <= math.sqrt(n):
        if n % i == 0:
            l = primeFactors(n / i)
            l.append(i)
            return l
        i += 1
    return [n]  # n is prime

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    factors = primeFactors(abs(N))
    if N < 0:
        factors.append(-1)
    factors.sort()
    print '%d = %s' % (N, ' x '.join(str(i) for i in factors))
