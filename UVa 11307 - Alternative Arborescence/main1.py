import sys
import numpypy as np
INF = 1 << 30
MAXC = 20


def dp(node, color):
    if memo[node, color] != INF:
        return memo[node, color]

    memo[node, color] = color
    for e in range(N):
        if graph[node, e]:
            memo[node, color] += min(dp(e, c)
                                     for c in range(1, MAXC) if c != color)
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
    memo = np.zeros((N, MAXC), dtype=np.int)
    memo.fill(INF)
    print min(dp(root, c) for c in range(1, MAXC))
