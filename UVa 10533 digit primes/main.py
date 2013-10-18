import sys
import bisect
from bitstring import BitArray


top = 100000
primes = set()
digitPrimes = []
b = BitArray(top)  # bitstring of ’0’ bits
for i in range(2, top):
    if not b[i]:
        primes.add(i)
        if sum(map(int, str(i))) in primes:
            digitPrimes.append(i)
            # i is prime, so set all its multiples to ’1’.
    b.set(True, range(i * i, top, i))

sys.stdin = open('input.txt')
cases = int(input())
for x in range(cases):
    t1, t2 = map(int, raw_input().split())
    print bisect.bisect(digitPrimes, t2) - bisect.bisect(digitPrimes, t1)
