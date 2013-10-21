import sys


def power(r, n):
    if n == 1:
        return r
    if n & 1:
        x = [r[0] * r[0] + r[1] * r[2], r[0] * r[1] + r[1] * r[3],
             r[2] * r[0] + r[3] * r[2], r[2] * r[1] + r[3] * r[3]]
        x = [i % (10 ** mod) for i in x]
        x = power(x, n >> 1)
        r = [r[0] * x[0] + r[1] * x[2], r[0] * x[1] + r[1] * x[3],
             r[2] * x[0] + r[3] * x[2], r[2] * x[1] + r[3] * x[3]]
        r = [i % (10 ** mod) for i in r]
        return r
    else:
        r = [r[0] * r[0] + r[1] * r[2], r[0] * r[1] + r[1] * r[3],
             r[2] * r[0] + r[3] * r[2], r[2] * r[1] + r[3] * r[3]]
        r = [i % (10 ** mod) for i in r]
        r = power(r, n >> 1)
        return r


sys.stdin = open('input.txt')
for _ in range(int(input())):
    a, b, n, mod = map(int, raw_input().split())
    x = [1, 1, 1, 0]
    r = power(x, n)
    print r[2] * b + r[3] * a
