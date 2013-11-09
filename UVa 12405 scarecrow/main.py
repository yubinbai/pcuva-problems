import sys
import numpypy as np

INF = 1 << 31
sys.stdin = open('input.txt')
for _ in range(int(input())):
    n = int(input())
    A = raw_input().strip()
    memo = np.zeros((n, n), dtype=np.int)
    memo.fill(-1)

    def dp(i, j):
        if i > j or j >= n or i < 0:
            return 0
        if memo[i, j] != -1:
            return memo[i, j]
        if j - i <= 2:
            if A[i:j + 1] != '#' * (j - i + 1):
                memo[i, j] = 1
            else:
                memo[i, j] = 0
            return memo[i, j]
        m = INF
        for k in range(i + 1, j):
            if A[k - 1:k + 2] != '###':
                m = min(m, dp(i, k - 2) + 1 + dp(k + 2, j))
            else:
                m = min(m, dp(i, k - 2) + dp(k + 2, j))
        memo[i, j] = m
        return m

    print dp(0, n - 1)
