'''
Created on Jul 24, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 30


def solve(par):
    N, K, cost = par
    dp = empty((K + 1, N + 1), dtype=int)
    dp.fill(INF)
    dp[0, 1] = 0

    for k in range(1, K + 1):
        for dest in range(1, N + 1):
            currMin = INF
            for depart in range(1, N + 1):
                if depart == dest:
                    continue
                cycle = cost[depart, dest, 0]
                pos = (k - 1) % cycle + 1
                if cost[depart, dest, pos] != 0:
                    currMin = min(
                        currMin, dp[k - 1, depart] + cost[depart, dest, pos])
            dp[k, dest] = currMin
    if dp[K, N] >= INF:
        return 'No flight possible.'
    else:
        return 'The best flight costs %d.' % dp[K, N]


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    while True:
        N, K = map(int, raw_input().split())
        if N == 0:
            break
        cost = zeros((N + 1, N + 1, 31), dtype=int)
                     # first place in each cell indicate length

        for i in range(1, N + 1):
            for j in range(1, N + 1):
                if j == i:
                    continue
                row = map(int, raw_input().split())
                for k, r in enumerate(row):
                    cost[i, j, k] = r
        print(solve((N, K, cost)))
