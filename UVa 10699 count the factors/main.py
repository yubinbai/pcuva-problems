import sys
import math

sys.stdin = open('input.txt')
while True:
    x = int(input())
    if not x:
        break
    n = x
    i = 2
    result = []
    while i <= math.sqrt(n):
        while n % i == 0:
            result.append(i)
            while n % i == 0:
                n /= i
        i += 1
    if n != 1:
        result.append(n)
    print '%d : %d' % (x, len(result))
