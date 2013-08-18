'''
Created on Jul 21, 2013
@author: Yubin Bai
'''
import sys
INF = 1 << 31
MAXN = 201


def solve(par):
    total, count = par
    N = int(total * 100 / 5)
    values = [1, 2, 4, 10, 20, 40]
    M = len(values)
    memo = [INF] * MAXN
    memo[0] = 0

    for i in range(M):
        for j in range(MAXN):
            # use only 0..i to get value j
            for k in range(int(count[i] + 1)):
                v1 = j + k * values[i]
                if v1 < MAXN and memo[v1] > memo[j] + k:
                    memo[v1] = memo[j] + k

    greedy = [0] * MAXN
    values.reverse()
    for i in range(MAXN):
        c = 0
        p = i
        for v in values:
            c += p // v
            p %= v
        greedy[i] = c

    minChange = INF
    for i in range(MAXN - N):
        minChange = min(minChange, memo[i + N] + greedy[i])
    return minChange


if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')

    while True:
        row = map(float, raw_input().split())
        total = row[-1]
        row.pop()
        if sum(row) == 0:
            break
        print(solve((total, row)))
