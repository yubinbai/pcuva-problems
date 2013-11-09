import sys
import math


def primeFactors(n):
    i = 2
    result = []
    while i <= math.sqrt(n):
        while n % i == 0:
            result.append(i)
            n /= i
        i += 1
    if n != 1:
        result.append(n)
    result.sort()
    return result

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    res = n
    for f in set(primeFactors(n)):
        res *= (1 - 1.0 / f)
    print int(res / 2)
