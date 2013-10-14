import sys
import math


def isPrime(N):
    for i in range(2, int(math.sqrt(N) + 1)):
        if (N % i == 0):
            return False
    return True

sys.stdin = open('input.txt')
while True:
    try:
        a, b = map(int, raw_input().split())
    except:
        break
    counter = 0
    for n in range(a, b + 1):
        if isPrime(n ** 2 + n + 41):
            counter += 1
    print '%.2f' % (100.0 * counter / (b - a + 1))
