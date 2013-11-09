import sys
import numpypy as np


def dp(x, y):
    if cost[x, y] != float('inf'):
        return cost[x, y]
    if x == y:
        cost[x, y] = 0
        return 0
    if x == y - 1:
        cost[x, y] = a[x][0] * a[y][0] * a[y][1]
        return cost[x, y]
    c = float('inf')
    for d in range(y - x):
        c1 = dp(x, x + d) + dp(x + d + 1, y) + a[x][0] * a[x + d][1] * a[y][1]
        if c > c1:
            c = c1
            decision[x, y] = d
    cost[x, y] = c
    return c


def make(x, y):
    if x == y:
        return 'A%d' % (x + 1)
    if x == y - 1:
        return '(A%d * A%d)' % (x + 1, y + 1)
    d = decision[x, y]
    return '(' + make(x, x + d) + ' * ' + make(x + d + 1, y) + ')'


sys.stdin = open('input.txt')
case = 0
while True:
    case += 1
    n = int(input())
    if not n:
        break
    a = []
    for _ in range(n):
        a.append(map(int, raw_input().split()))
    cost = np.zeros((n, n))
    cost.fill(float('inf'))
    decision = np.zeros((n, n))
    dp(0, n - 1)
    print 'Case %d:' % case, make(0, n - 1)
