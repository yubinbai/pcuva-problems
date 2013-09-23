import sys
from math import *


def extended_gcd(a, b):
    x, y = 0, 1
    lastx, lasty = 1, 0
    while b:
        q = a // b
        a, b = b, a % b
        x, lastx = lastx - q * x, x
        y, lasty = lasty - q * y, y
    return a, lastx, lasty

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    x, k = map(int, raw_input().split())
    a = int(floor(x * 1.0 / k))
    b = int(ceil(x * 1.0 / k))
    g, x1, y1 = extended_gcd(a, b)
    print x1 * x / g, y1 * x / g
