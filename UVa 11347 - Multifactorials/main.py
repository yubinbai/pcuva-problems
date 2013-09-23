import sys
import operator
from collections import Counter
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
numTest = int(input())
for itertest in range(numTest):
    s = raw_input().strip()
    c = Counter(s)
    try:
        f = c['!']
    except:
        f = 0
    factors = []
    n = int(s.strip('!'))
    for x in range(n, 1, -f):
        factors += primeFactors(x)
    c = Counter(factors)
    total = 1
    for k, v in c.items():
        total *= (1 + v)
    if total < 1E18:
        print total
    else:
        print 'Infinity'
