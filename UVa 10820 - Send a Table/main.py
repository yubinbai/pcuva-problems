import sys
import operator
import math
MAXN = 50001


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    while i <= math.sqrt(n):
        if n % i == 0:
            l = primeFactors(n / i)
            l.append(i)
            return l
        i += 1
    return [n]  # n is prime

result = [0, 1]
sumResult = [0, 1]
for x in range(2, MAXN):
    factors = set(primeFactors(x))
    phi = x * reduce(operator.mul, map(lambda p: 1.0 - 1.0 / p, factors))
    result.append(int(phi) * 2)
for x in range(2, MAXN):
    sumResult.append(sumResult[-1] + result[x])

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    print sumResult[N]
