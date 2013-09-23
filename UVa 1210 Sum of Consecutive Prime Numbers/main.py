import sys
from bitstring import BitArray
from collections import Counter


def prime_sieve(top=10005):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

sys.stdin = open('input.txt')
primes = list(prime_sieve())
primeSums = [0]
for i in range(len(primes)):
    primeSums.append(primeSums[-1] + primes[i])
diffSums = []
for i in range(len(primes) - 1):
    for j in range(i, len(primes)):
        diffSums.append(primeSums[j] - primeSums[i])
c = Counter(diffSums)
while True:
    n = int(input())
    if not n:
        break
    else:
        try:
            print c[n]
        except:
            print 0
