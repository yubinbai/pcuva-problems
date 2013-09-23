from collections import deque
import sys
import numpypy as np


def dp(node, color):
    if memo[node, color] != INF:
        return memo[node, color]
    visited[node] = 1
    if color:
        memo[node, color] = 1
        for e in range(1, N + 1):
            if not visited[e] and graph[node, e]:
                memo[node, color] += min(dp(e, 0), dp(e, 1))
    else:
        memo[node, color] = 0
        for e in range(1, N + 1):
            if not visited[e] and graph[node, e]:
                memo[node, color] += dp(e, 1)
    visited[node] = 0
    return memo[node, color]


INF = 1 << 30
sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    graph = np.zeros((N + 1, N + 1), dtype=np.int16)
    for i in range(1, N + 1):
        line = map(int, raw_input().split())
        for j in range(line[0]):
            graph[i, line[j + 1]] = 1

    memo = np.empty((N + 1, 2), dtype=int)
    memo.fill(INF)
    visited = np.zeros((N + 1), dtype=int)
    visited[1] = 1
    print min(dp(1, 0), dp(1, 1))
