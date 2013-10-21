import sys
import collections
from bitstring import BitArray


def prime_sieve(top=210):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

sys.stdin = open('input.txt')
primes = list(prime_sieve())

for case in range(int(input())):
    c = collections.Counter(raw_input().strip())
    result = []
    for k, v in c.items():
        if v in primes:
            result.append(k)
    result.sort()
    if result:
        print 'Case %d: %s' % (case + 1, ''.join(result))
    else:
        print 'Case %d: empty' % (case + 1)
