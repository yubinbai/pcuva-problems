import sys
import numpypy as np
INF = 1 << 30


def dp(node, color):
    if memo[node, color] != INF:
        return memo[node, color]
    if color == 1:
        memo[node, color] = 1
        for e in range(N):
            if graph[node, e]:
                memo[node, color] += dp(e, 2)
    else:
        memo[node, color] = 2
        for e in range(N):
            if graph[node, e]:
                memo[node, color] += dp(e, 1)
    return memo[node, color]

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    graph = np.zeros((N, N), dtype=np.byte)
    for x in xrange(1, N + 1):
        u, v = raw_input().split(':')
        u = int(u)
        v = map(int, v.split())
        for vi in v:
            graph[u, vi] = 1
    raw_input()

    root = 0
    while True:
        newRoot = root
        for i in range(N):
            if graph[i, root]:
                newRoot = i
                break
        if newRoot == root:
            break
        else:
            root = newRoot
    memo = np.zeros((N, 3), dtype=np.int)
    memo.fill(INF)
    print min(dp(root, 2), dp(root, 1))
