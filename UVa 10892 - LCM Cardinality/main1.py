import sys
from math import sqrt
from itertools import product


def getGCD(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a


def getFactors(number):
    factors = set()
    for i in range(1, int(sqrt(number)) + 1):
        if not number % i:
            factors.add(i)
            factors.add(number / i)
    factors = list(factors)
    factors.sort()
    return factors


sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    result = 0
    factors = getFactors(N)
    nFactors = len(factors)
    for i in range(nFactors):
        for j in range(i, nFactors):
            f1 = factors[i]
            f2 = factors[j]
            g = getGCD(f1, f2)
            if g * N == f1 * f2:
                result += 1
    print result
