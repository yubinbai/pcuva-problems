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
numTest = int(input())
for itertest in range(numTest):
    L, U = map(int, raw_input().split())
    it = L
    result, maxI = 0, -1
    while it <= U:
        f = primeFactors(it)
        counter = Counter(f)
        result1 = 1
        for c in counter:
            result1 *= counter[c] + 1
        if result1 > result:
            result = result1
            maxI = it
        it += 1
    print 'Between %d and %d, %d has a maximum of %d divisors.' % \
        (L, U, maxI, result)
