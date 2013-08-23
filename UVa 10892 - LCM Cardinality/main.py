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
    result = set()
    factors = getFactors(N)
    # print len(factors)
    # print factors
    for f1, f2, f3 in product(factors, repeat=3):
        if N * f1 == f2 * f3 and f2 <= f3 and getGCD(f2, f3) == f1:
            result.add((f2, f3))

    print len(result)
