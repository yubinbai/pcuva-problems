import sys
import math

sys.stdin = open('input.txt')
while True:
    n = raw_input().strip()
    if n == '0':
        break
    b = max(ord(c) - ord('0') for c in n)
    for base in range(b, 100):
        total = sum((ord(c) - ord('0')) *
                    base ** i for i, c in enumerate(reversed(n)))
        if int(math.sqrt(total)) ** 2 == total:
            print base
            break
