'''
Created Jul 26, 2013
'''
import sys
from numpypy import *


def solve(par):
    N, M, likes = par
    dp = empty((N, 1 << M), dtype=int)
    dp.fill(-1)

    def _solve(step, status):
        if step == N:
            return 1

        if dp[step, status] != -1:
            return dp[step, status]

        sln = 0
        for like in likes[step]:
            num = like - 1
            if status & (1 << num):
                continue
            sln += _solve(step + 1, status | (1 << num))
        dp[step, status] = sln
        return sln

    return _solve(0, 0)


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    N, M = map(int, raw_input().split())
    likes = []
    for i in range(N):
        row = map(int, raw_input().split())
        likes.append(row[1:])
    print(solve((N, M, likes)))
