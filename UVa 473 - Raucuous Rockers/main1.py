import sys
from numpypy import *
INF = 1 << 31


def solve(par):
    N, T, M, song = par
    # state: last song, last song disk pos, remainT
    dp = zeros((2, M + 1, T + 1), dtype=byte)
    for i in range(N - 1, -1, -1):
        for r in range(M, -1, -1):
            for t in range(T, -1, -1):
                dp[i % 2, r, t] = dp[(i + 1) % 2, r, t]
                if t >= song[i]:
                    dp[i % 2, r, t] = max(
                        dp[i % 2, r, t], dp[(i + 1) % 2, r, t - song[i]] + 1)
                if r > 0:
                    dp[i % 2, r, t] = max(
                        dp[i % 2, r, t], dp[(i + 1) % 2, r - 1, T - song[i]] + 1)
    return max(dp[i, M, 0] for i in range(2))

if __name__ == '__main__':

    sys.stdin = open('input.txt', 'r')
    numTest = int(input())
    for itertest in range(numTest):
        raw_input()
        N, T, M = map(int, raw_input().split())
        array = map(int, raw_input().split(','))
        print(solve((N, T, M, array)))
