import sys
import numpypy as np

memo = np.zeros((101, 101), dtype=np.int)
memo.fill(-1)
for i in range(101):
    memo[0, i] = 1
    memo[i, 1] = 1


def dp(n, k):
    if memo[n, k] != -1:
        return memo[n, k]
    memo[n, k] = 0
    for i in range(n + 1):
        memo[n, k] += dp(n - i, k - 1)
        memo[n, k] %= 1000000
    return memo[n, k]

sys.stdin = open('input.txt')
while True:
    n, k = map(int, raw_input().split())
    if not n and not k:
        break
    print dp(n, k)
