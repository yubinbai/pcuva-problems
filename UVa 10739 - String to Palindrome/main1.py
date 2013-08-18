from numpypy import *
import sys
INF = 1 << 30


def solve(s):
    N = len(s)
    memo = empty((N + 1, N + 1), dtype=int)
    memo.fill(-1)

    def moves(i, j):
        if i > j:
            return 0
        if memo[i, j] != -1:
            return memo[i, j]
        if s[i] == s[j]:
            memo[i, j] = min(
                moves(i + 1, j - 1), moves(i + 1, j) + 1, moves(i, j - 1) + 1)
        else:
            memo[i, j] = min(
                moves(i + 1, j - 1), moves(i + 1, j), moves(i, j - 1)) + 1
        return memo[i, j]
    return moves(0, N - 1)


sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    print('Case#%d: %d' % (itertest + 1, solve(raw_input().strip())))
