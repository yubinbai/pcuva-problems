import sys
import bisect
from bitstring import BitArray


def prime_sieve(top=1000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

sys.stdin = open('input.txt')
primes = list(prime_sieve())
while True:
    n = int(input())
    if n == 0:
        break
    counter = 0
    for p in primes:
        if p > n - p:
            break
        idx = bisect.bisect_left(primes, n - p)
        if primes[idx] == n - p:
            counter += 1
    print counter
