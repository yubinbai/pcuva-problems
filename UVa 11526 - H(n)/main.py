from math import sqrt
import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    number = int(input())
    prevQuotient = currQuotient = number
    length = int(sqrt(number))
    total = 0
    for i in range(1, length + 1):
        currQuotient = number // i
        total += currQuotient
        total += (prevQuotient - currQuotient) * (i - 1)
        prevQuotient = currQuotient
    if prevQuotient > length:
        total += length
    print total
