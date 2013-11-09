import sys
import numpypy as np


def dp(status, target):
    if memo[status, target] != -1:
        return memo[status, target]
    if target == 0:
        memo[status, target] = 1
        return 1
    for i in range(n):
        if not (status & (1 << i)) and target - w[i] >= 0:
            if dp(status | (1 << i), target - w[i]):
                memo[status, target] = 1
                return 1
    memo[status, target] = 0
    return 0


sys.stdin = open('input.txt')
for _ in range(int(input())):
    w = map(int, raw_input().split())
    s = sum(w)
    n = len(w)
    if s & 1:
        print 'NO'
    else:
        memo = np.zeros((1 << n, s // 2 + 1), dtype=np.byte)
        memo.fill(-1)
        if dp(0, s // 2):
            print 'YES'
        else:
            print 'NO'
