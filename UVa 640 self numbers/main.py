from bitstring import BitArray
import sys
MAXN = 1000000


bits = BitArray(MAXN)
for x in range(1, MAXN):
    if not bits[x]:
        print x
        while True:
            next = x + sum(ord(c) - ord('0') for c in str(x))
            if next < MAXN:
                bits.set(True, next)
                x = next
            else:
                break
