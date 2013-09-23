import sys
import math


def allFactors(number):
    result = []
    for i in range(1, int(math.sqrt(number)) + 1):
        a, b = divmod(number, i)
        if b == 0 and i <= a:
            result.append(i)
            if a != i:
                result.append(a)
    result.sort()
    return result
sys.stdin = open('input.txt')
array = map(int, raw_input().split())
for n in array:
    if n == 0:
        break
    factors = allFactors(n)
    total = sum(factors[:-1])
    # print factors, n, total
    if total > n:
        print '%d abundant' % n
    elif total < n:
        print '%d deficient' % n
    else:
        print '%d perfect' % n
