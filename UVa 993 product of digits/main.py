import sys
from collections import Counter
import math


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    result = []
    while i <= math.sqrt(n):
        while n % i == 0:
            result.append(i)
            n /= i
        i += 1
    if n != 1:
        result.append(n)
    result.sort()
    return result

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    n = int(input())
    if n == 1:
        print 1
        continue
    factors = primeFactors(n)
    if any(x > 7 for x in factors):
        print -1
    else:
        digits = []
        c = Counter(factors)
        if 2 not in c:
            c[2] = 0
        if 3 not in c:
            c[3] = 0
        while c[2] >= 3:
            digits.append(8)
            c[2] -= 3
        while c[3] >= 2:
            digits.append(9)
            c[3] -= 2
        if c[2] and c[3]:
            digits.append(6)
            c[2] -= 1
            c[3] -= 1
        if c[2] >= 2:
            c[2] -= 2
            digits.append(4)
        for d in [2, 3, 5, 7]:
            if c[d] > 0:
                for i in range(c[d]):
                    digits.append(d)
        print ''.join(str(d) for d in sorted(digits))
