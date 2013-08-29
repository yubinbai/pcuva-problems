import sys
from math import *
from collections import Counter
INF = 1 << 30


def primeFactors(n):
    '''
    lists prime factors of a natural number, from greatest to smallest
    '''
    i = 2
    while i <= sqrt(n):
        if n % i == 0:
            l = primeFactors(n / i)
            l.append(i)
            return l
        i += 1
    return [n]  # n is prime

sys.stdin = open('input.txt')
while True:
    try:
        N, B = map(int, raw_input().split())
    except:
        break
    factors = primeFactors(B)
    counter = Counter(factors)
    zeros = INF
    for f in counter:
        countF = 0
        N2 = N
        while N2:
            countF += N2 // f
            N2 //= f
        # print f, countF
        zeros = min(zeros, countF / counter[f])
    # print zeros
    logNfact = sum(log(i) for i in range(2, N + 1))
    # print logNfact
    digits = int(logNfact / log(B)) + 1
    print zeros, digits
