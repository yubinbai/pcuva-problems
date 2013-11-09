import sys


def pow5(n):
    if n == 0:
        return 1.000, 0
    if n == 1:
        return 5.000, 0
    a, e = pow5(n >> 1)
    a *= a
    e += e
    if n & 1:
        a *= 5
    while a > 10:
        a /= 10
        e += 1
    return a, e


sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    a, e = pow5(n)
    print '2^-%d = %.3fe%d' % (n, a, e - n)
