'''
Created on Jul 19, 2013
@author: Yubin Bai
'''
import sys
import time
INF = 1 << 31
'''
f[step][moneyLeft]:number of garments bought
f[step][moneyLeft] = max(f[step-1][moneyLeft+p[step][i]] + 1, f[step-1][moneyLeft])
'''


def solve(par):
    M, C, items = par
    memo = []
    for i in range(C + 1):
        memo.append([-1 * INF] * (M + 1))
    memo[0][M] = 0
    for i in range(C):
        for c in range(M + 1):
            if memo[i][c] > memo[i + 1][c]:
                memo[i + 1][c] = memo[i][c]
            for it in items[i]:
                if c - it >= 0 and memo[i][c] + 1 > memo[i + 1][c - it]:
                    memo[i + 1][c - it] = memo[i][c] + 1
    index, currMax = -1, -1
    for i, c in enumerate(memo[C]):
        if c > currMax:
            index, currMax = i, c

    if currMax < C:
        return 'no solution'
    else:
        return M - index


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    numTests = int(raw_input())
    for iterTest in range(numTests):
        M, C = map(int, raw_input().split())
        items = []
        for i in range(C):
            items.append(map(int, raw_input().split())[1:])
        print(solve((M, C, items)))
