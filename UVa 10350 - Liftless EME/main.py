from numpypy import *
import sys

INF = 1 << 30
sys.stdin = open('input.txt')
while True:
    try:
        name = raw_input().strip()
    except:
        break
    print name
    N, M = map(int, raw_input().split())
    dist = zeros((N - 1, M, M), dtype=int)
    for k in range(N - 1):
        for i in range(M):
            line = map(int, raw_input().strip().split())
            for j in range(M):
                dist[k, i, j] = line[j]
    memo = zeros((N, M), dtype=int)
    memo.fill(INF)
    for i in range(M):
        memo[0, i] = 0

    def solve(k, i):
        '''
        k-th floor at i-th hole
        '''
        if memo[k, i] != INF:
            return memo[k, i]
        for j in range(M):
            memo[k, i] = min(memo[k, i], solve(k - 1, j) + dist[k - 1, j, i])
        return memo[k, i]

    print min(solve(N - 1, i) for i in range(M)) + 2 * (N - 1)
