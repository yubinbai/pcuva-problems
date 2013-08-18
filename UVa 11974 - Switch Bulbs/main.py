'''
Created on Jul 27, 2013
@author: Yubin Bai
'''
import sys
from numpypy import *
INF = 1 << 30

sys.stdin = open('input.txt', 'r')
numTests = int(input())
for itertest in range(numTests):
    N, M = map(int, raw_input().split())
    graph = zeros((M + 1), dtype=int)
    for i in range(1, M + 1):
        row = map(int, raw_input().strip().split())
        for j, r in enumerate(row):
            if r:
                graph[i] |= (1 << j)
    dp = empty((M + 1, (1 << N) + 1), dtype=int)
    dp.fill(INF)
    dp[0, 0] = 0

    def _solve(step, state):
        if step == 0:
            return dp[0, state]
        if dp[step, state] != INF:
            return dp[step, state]
        for i in range(1, M + 1):
            dp[step, state] = min(
                dp[step, state], _solve(step - 1, state ^ graph[i]) + 1)
        return dp[step, state]

    if _solve(M, (1 << N) - 1) < INF:
        print(_solve(M, (1 << N) - 1))
    else:
        print('IMPOSSIBLE')
