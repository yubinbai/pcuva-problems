from numpypy import *
from heapq import *
import sys
INF = 1 << 3


def dijkstra(source):
    dist = zeros((N))
    for i in range(N):
        dist[i] = graph[source, i]
    dist[source] = 0
    visited = zeros((N), dtype=byte)
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
itertest = 1
while True:
    N = int(input())
    if not N:
        break
    start = int(input()) - 1
    graph = zeros((N, N), dtype=int)
    graph.fill(INF)
    while True:
        p, q = map(int, raw_input().split())
        if p == 0 and q == 0:
            break
        graph[p - 1, q - 1] = -1

    dist = dijkstra(start)
    minD, minI = min((dist[i], i) for i in range(N))
    print 'Case #%d: The longest path from %d has length %d, finishing at %d.' %\
        (itertest, start + 1, -1 * minD, minI + 1)
