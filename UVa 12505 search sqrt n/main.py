from decimal import Decimal, getcontext
import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    n, s = raw_input().split()
    getcontext().prec = 140
    n = Decimal(int(n))
    r = n.sqrt()
    r -= int(r)
    res = []
    for _ in range(140):
        r *= 2
        if r > 1:
            res.append('1')
            r -= 1
        else:
            res.append('0')
    print ''.join(res).index(s)
