import sys


def f(n):
    if n >= 101:
        return n - 10
    elif memo[n] != -1:
        return memo[n]
    else:
        memo[n] = f(n + 11)
        return memo[n]
sys.stdin = open('input.txt')
memo = [-1] * 101
for x in range(1, 101):
    f(x)
while True:
    n = int(input())
    if not n:
        break
    print 'f91(%d) = %d' % (n, f(n))
