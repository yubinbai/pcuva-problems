import sys
import math


def extended_gcd(a, b):
    '''
    return gcd, x0, y0
    for equation ax+by=g
    '''
    x, y = 0, 1
    lastx, lasty = 1, 0
    while b:
        q = a // b
        a, b = b, a % b
        x, lastx = lastx - q * x, x
        y, lasty = lasty - q * y, y
    return a, lastx, lasty

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    c1, a = map(int, raw_input().split())
    c2, b = map(int, raw_input().split())
    gcd, x, y = extended_gcd(a, b)
    x *= n / gcd
    y *= n / gcd
    if n % gcd:
        print 'failed'
    else:
        if x < 0:
            k1 = math.ceil(x / (-1.0 * b / gcd))
            k2 = math.floor(y / (1.0 * a / gcd))
        else:
            k1 = math.floor(x / (-1.0 * b / gcd))
            k2 = math.ceil(y / (1.0 * a / gcd))
        print k1, k2
        x1, y1 = x + k1 * b / gcd, y - k1 * a / gcd
        x2, y2 = x + k2 * b / gcd, y - k2 * a / gcd
        if x1 * c1 + y1 * c2 > x2 * c1 + y2 * c2:
            print x2, y2
        else:
            print x1, y1
