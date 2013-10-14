from bitstring import BitArray
import bisect
import sys

top = 2000000
b = BitArray(top)  # bitstring of ’0’ bits
for i in range(2, top):
    if not b[i]:
        b.set(True, range(i * i, top, i))
sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    rev = int(str(n)[::-1])
    if not b[n] and not b[rev]:
        print '%d is emirp.' % n
    elif not b[n]:
        print '%d is prime.' % n
    else:
        print '%d is not prime.' % n
