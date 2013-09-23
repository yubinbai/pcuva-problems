import sys
import math


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


def sumDigit(number):
    result = 0
    while number:
        result += number % 10
        number //= 10
    return result

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    n = int(input())
    n += 1
    while True:
        factors = primeFactors(n)
        if len(factors) > 1 and \
                sumDigit(n) == sum(sumDigit(f) for f in factors):
            print n
            break
        else:
            n += 1
