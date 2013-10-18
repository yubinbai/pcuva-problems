import sys
import decimal

decimal.getcontext().prec = 1010
sys.stdin = open('input.txt')
n = int(input())
for _ in range(n):
    a, b = map(decimal.Decimal, raw_input().strip().split())
    s = str(a + b).rstrip('0')
    if s[-1] == '.':
        print s + '0'
    else:
        print s

