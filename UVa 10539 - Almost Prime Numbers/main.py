from bisect import *
from bitstring import BitArray
import sys
MAXN = 1000005


def prime_sieve(top=MAXN):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

if __name__ == '__main__':
    primes = list(prime_sieve())
    almostPrimes = []
    for p in primes:
        p1 = p ** 2
        while p1 < MAXN:
            almostPrimes.append(p1)
            p1 *= p
    almostPrimes.sort()

    sys.stdin = open('input.txt')
    numTest = int(input())
    for x in range(numTest):
        left, right = map(int, raw_input().split())
        i1 = bisect_right(almostPrimes, left)
        i2 = bisect_right(almostPrimes, right)
        print(i2 - i1)
