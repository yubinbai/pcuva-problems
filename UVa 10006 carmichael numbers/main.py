import sys
from bitstring import BitArray


def prime_sieve(top=66000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

primes = set(prime_sieve())
sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    flag = True
    for i in range(2, N):
        if pow(i, N, N) != i:
            flag = False
            break
    if flag and (N not in primes):
        print 'The number %d is a Carmichael number.' % N
    else:
        print '%d is normal.' % N
