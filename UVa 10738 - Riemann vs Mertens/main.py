from numpypy import *
from bitstring import *
import sys
MAXN = 1000000


def sievePrime(top=MAXN):
    sieve = BitArray(top)
    for x in range(2, top):
        if not sieve[x]:
            yield x
            sieve.set(True, range(x * x, top, x))


def muCalc(number):
    curr = number
    counter = 0
    for p in primes:
        while curr % p == 0:
            counter += 1
            curr /= p
        if counter or p ** 2 > curr:
            break
    if not counter:  # n is prime
        return -1
    # n is not prime
    if mu[curr] == 0 or counter > 1:
        return 0
    if mu[curr] == 1:
        return -1
    else:
        return 1


primes = list(sievePrime())
mu = zeros((MAXN), dtype=int8)
M = zeros((MAXN), dtype=int)
mu[1] = 1
for i in range(2, MAXN):
    mu[i] = muCalc(i)
for i in range(1, MAXN):
    M[i] = M[i - 1] + mu[i]

sys.stdin = open('input.txt')
for line in sys.stdin:
    n = int(line)
    if n == 0:
        break
    else:
        print('%8d%8d%8d' % (n, mu[n], M[n]))
