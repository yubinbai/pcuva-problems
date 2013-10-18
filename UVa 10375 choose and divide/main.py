import sys
import collections
from bitstring import BitArray
import math


def prime_sieve(top=10000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))


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
primes = list(prime_sieve(10002))
while True:
    try:
        p, q, r, s = map(int, raw_input().split())
    except:
        break
    total = dict([(a, 0) for a in primes])

    for i in range(p - q + 1, p + 1):
        c = collections.Counter(primeFactors(i))
        for k, v in c.items():
            total[k] += v

    for i in range(1, q + 1):
        c = collections.Counter(primeFactors(i))
        for k, v in c.items():
            total[k] -= v

    for i in range(1, s + 1):
        c = collections.Counter(primeFactors(i))
        for k, v in c.items():
            total[k] += v

    for i in range(r - s + 1, r + 1):
        c = collections.Counter(primeFactors(i))
        for k, v in c.items():
            total[k] -= v
    # print total
    result = 1.0
    for k, v in total.items():
        if v:
            result *= pow(k, v)
    print '%.5f' % result
