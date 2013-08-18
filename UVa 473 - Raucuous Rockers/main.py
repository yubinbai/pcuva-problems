import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, T, M, song = par
    # state: last song, last disk, remainT
    dp = zeros((N + 1, M + 1, T + 1), dtype=int)
    for i in range(N - 1, -1, -1):
        for r in range(M, -1, -1):
            for t in range(T, -1, -1):
                dp[i, r, t] = dp[i + 1, r, t]
                if t >= song[i]:
                    dp[i, r, t] = max(
                        dp[i, r, t], dp[i + 1, r, t - song[i]] + 1)
                if r > 0:
                    dp[i, r, t] = max(
                        dp[i, r, t], dp[i + 1, r - 1, T - song[i]] + 1)
    return max(dp[i, M, 0] for i in range(N))

if __name__ == '__main__':

    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        raw_input()
        N, T, M = map(int, raw_input().split())
        array = map(int, raw_input().split(','))
        print(solve((N, T, M, array)))
