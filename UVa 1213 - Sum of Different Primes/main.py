import sys
from bitstring import BitArray
from numpypy import *
INF = 1 << 31
MAXN = 1500
MAXK = 15


def prime_sieve(top=10000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))


if __name__ == '__main__':
    primes = list(prime_sieve(MAXN))
    memo = zeros((MAXK, MAXN), dtype=int64)
    memo[0, 0] = 1
    for prime in primes:
        for j in range(MAXN - 1, -1, -1):
            if j >= prime:
                for k in range(1, MAXK):
                    memo[k, j] += memo[k - 1, j - prime]

    sys.stdin = open('input.txt', 'r')
    while True:
        N, K = map(int, raw_input().split())
        if N == 0:
            break
        print(memo[K, N])
