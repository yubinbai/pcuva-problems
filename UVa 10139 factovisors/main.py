import sys
import math
from collections import Counter


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
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
        n, m = map(int, raw_input().split())
    except:
        break

    factors = Counter(primeFactors(m))
    flag = True
    for f in factors:
        f1 = f
        c = 0
        while f1 <= n:
            c += n / f1
            f1 *= f
        if c < factors[f]:
            flag = False
            break
    if flag:
        print '%d divides %d!' % (m, n)
    else:
        print '%d does not divides %d!' % (m, n)
