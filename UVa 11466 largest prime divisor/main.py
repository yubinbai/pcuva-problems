import sys
from bitstring import BitArray

primes = []
top = 10000099
b = BitArray(top)  # bitstring of ’0’ bits
for i in range(2, top):
    if not b[i]:
        primes.append(i)
        b.set(True, range(i * i, top, i))


def lpd(n):
    res = 0
    for p in primes:
        if n > 1:
            while n % p == 0:
                res = p
                n /= p
        else:
            break
    return max(n, res)

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    res = lpd(n)
    if res == n:
        print -1
    else:
        print res
