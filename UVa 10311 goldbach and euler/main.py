import sys
import bisect
import math
from bitstring import BitArray


def prime_sieve(top=100000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    last = int(math.sqrt(top)) + 1
    for i in range(2, last):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

sys.stdin = open('input.txt')
primes = list(prime_sieve())
while True:
    try:
        n = int(input())
    except:
        break
    if n % 2:
        i1 = bisect.bisect_left(primes, n - 2)
        if primes[i1] == n - 2:
            print '%d is the sum of %d and %d.' % (n, 2, n - 2)
        else:
            print '%d is not the sum of two primes!' % n
    else:
        i1 = bisect.bisect_left(primes, n // 2 - 1)
        i2 = bisect.bisect_left(primes, n // 2 + 1)
        flag = False
        while i1 >= 0 and i2 < len(primes):
            if primes[i1] + primes[i2] == n:
                print '%d is the sum of %d and %d.' % (n, primes[i1], primes[i2])
                flag = True
                break
            elif primes[i1] + primes[i2] > n:
                i1 -= 1
            else:
                i2 += 1
        if not flag:
            print '%d is not the sum of two primes!' % n
