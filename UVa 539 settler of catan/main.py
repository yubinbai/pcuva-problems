import sys
import numpypy as np


def dfs(s):
    res = 0
    for t in range(n):
        if graph[s, t] and not visited[s, t]:
            visited[s, t] = visited[t, s] = 1
            res = max(res, dfs(t) + 1)
            visited[s, t] = visited[t, s] = 0
    return res

sys.stdin = open('input.txt')
while True:
    n, m = map(int, raw_input().split())
    if not n and not m:
        break
    graph = np.zeros((n, n), dtype=np.byte)
    visited = np.zeros((n, n), dtype=np.byte)
    for _ in range(m):
        a, b = map(int, raw_input().split())
        graph[a, b] = graph[b, a] = 1
    res = 0
    for i in range(n):
        visited.fill(0)
        res = max(res, dfs(i))
    print res
