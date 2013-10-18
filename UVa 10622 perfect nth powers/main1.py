import math
import collections
import sys


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


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
while True:
    n = int(input())
    if not n:
        break
    factors = collections.Counter(primeFactors(n))
    print reduce(gcd, factors.values())
