import sys
from heapq import *
from numpypy import *
INF = 1 << 30


def dijkstra(source):
    dist = zeros(N)
    for i in range(N):
        dist[i] = graph[source, i]
    dist[source] = 0
    visited = zeros(N, dtype=byte)
    heap = []
    for i in range(N):
        heappush(heap, (dist[i], i))
    visitedCount = 0
    while visitedCount <= N and heap:
        d1, v1 = heappop(heap)
        if visited[v1]:
            continue
        dist[v1] = d1
        visited[v1] = 1
        visitedCount += 1
        for v2 in range(N):
            value = graph[v1, v2] + d1
            if dist[v2] > value:
                dist[v2] = value
                heappush(heap, (value, v2))
    return dist

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N, M, S, T = map(int, raw_input().split())
    graph = empty((N, N), dtype=int)
    graph.fill(INF)
    for i in range(M):
        f, t, v = map(int, raw_input().split())
        graph[f, t] = graph[t, f] = v
    dist = dijkstra(S)
    if dist[T] < INF:
        print 'Case #%d: %d' % (itertest + 1, dist[T])
    else:
        print 'Case #%d: unreachable' % (itertest + 1)
