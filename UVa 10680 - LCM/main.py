import sys
import math
from bitstring import BitArray


def prime_sieve(top=1000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

primes = list(prime_sieve())
sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    powers = dict([(p, int(math.log(N, p))) for p in primes if p <= max(5, N)])
    # print N, powers
    result = 1
    for p in primes:
        if p > N:
            break
        if p != 2 and p != 5:
            result *= pow(p, powers[p], 10)

    if powers[5] > powers[2]:
        for i in range(powers[5] - powers[2]):
            result = result * 5 % 10
    elif powers[2] > powers[5]:
        for i in range(powers[2] - powers[5]):
            result = result * 2 % 10
    print N, result
