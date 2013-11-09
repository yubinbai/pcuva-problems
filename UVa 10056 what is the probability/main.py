import sys
from decimal import Decimal

sys.stdin = open('input.txt')
for _ in range(int(input())):
    n, p, i = map(float, raw_input().strip().split())
    print '%.4f' % ((1 - p) ** (n - i) * p / (1 - (1 - p) ** n))
