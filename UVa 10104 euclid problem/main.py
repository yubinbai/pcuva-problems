import sys


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
    try:
        a, b = map(int, raw_input().split())
    except:
        break
    gcd, x, y = extended_gcd(a, b)
    print x, y, gcd
