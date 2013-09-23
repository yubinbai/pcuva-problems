import sys
import numpypy as np


def dp(size, stack):
    if size == 0:
        memo[size, stack] = (stack == 3)
        return memo[size, stack]
    elif (memo[size, stack] != -1):
        return memo[size, stack]
    else:
        if stack == 3:
            # L or U would do the same
            memo[size, stack] = dp(size - 1, stack) * 2
        else:
            # add L or U
            memo[size, stack] = dp(size - 1, 0) + dp(size - 1, stack + 1)
        return memo[size, stack]


sys.stdin = open('input.txt')
memo = np.zeros((40, 4), dtype=int)
memo.fill(-1)
while True:
    n = int(input())
    if not n:
        break
    print dp(n, 0)
