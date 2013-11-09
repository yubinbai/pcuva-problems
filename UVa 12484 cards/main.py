import sys
import numpypy as np

INF = 1 << 35
sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
        A = map(int, raw_input().split())
    except:
        break
    memo = np.zeros((n, n), dtype=np.int64)
    memo.fill(-1 * INF)

    def dp(a, b):
        if memo[a, b] != -1 * INF:
            return memo[a, b]
        if a == b - 1:
            memo[a, b] = max(A[a], A[b])
            return memo[a, b]
        mA = A[a] + max(dp(a + 1, b - 1), dp(a + 2, b))
        mB = A[b] + max(dp(a + 1, b - 1), dp(a, b - 2))
        memo[a, b] = min(mA, mB)
        return memo[a, b]

    print dp(0, n - 1)
