'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
from collections import Counter
from math import sqrt
INF = 1 << 31
MAXN = 2005


def solve(par):
    t, h, f, trees = par
    acorns = []
    for i in range(t):
        acorns.append([0] * MAXN)

    for i in range(t):
        for a in trees[i]:
            acorns[i][a] += 1

    dp = [0] * (MAXN + f)
    for i in range(h, 0, -1):
        for n in range(t):
            curr = max(acorns[n][i + 1], dp[i + f])
            # curr: best from this tree + 1 or above
            curr += acorns[n][i]
            acorns[n][i] = curr
            dp[i] = max(curr, dp[i])
    return dp[1]

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(input())
    for itertest in range(numTests):
        t, h, f = map(int, raw_input().split())
        trees = []
        for i in range(t):
            trees.append(map(int, raw_input().split()[1:]))
        print(solve((t, h, f, trees)))
