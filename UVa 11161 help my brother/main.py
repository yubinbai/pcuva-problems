import sys
import math

sys.stdin = open('input.txt')
fib = []
a, b = 0, 1
for _ in range(1511):
    fib.append(b)
    a, b = b, a + b
sumFib = [0] + fib[:1]
for i in range(1, len(fib)):
    sumFib.append(fib[i] + sumFib[-1])
while True:
    n = int(input())
    if not n:
        break
    left, right = sumFib[n - 1:n + 1]
    print int(math.ceil((left + right - 2) / 2.0))
