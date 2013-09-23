import numpypy as np
import sys
from bitstring import BitArray


def prime_sieve(top=1000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))

a = list(prime_sieve(10000))
size = len(a)

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    counter = 0
    head = 0
    tail = size - 1
    while (a[tail] > n):
        tail -= 1
    while (head <= tail):
        p = a[tail]
        while (p * a[head] <= n):
            p *= a[head]
            head += 1
        tail -= 1
        counter += 1
    print counter
