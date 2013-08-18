import sys
from collections import deque
from pqdict import PQDict
from numpypy import *
INF = 1 << 30


def dijkstra(source):
    distResults = [INF] * (N + 1)
    distResults[source] = 0
    dist = PQDict()
    for i in range(1, N + 1):
        dist[i] = distResults[i]

    while dist:
        v1, d1 = dist.popitem()
        distResults[v1] = d1
        if d1 == INF:
            break
        for v2 in range(1, N + 1):
            if v2 in dist:
                dist[v2] = min(dist[v2], graph[v1, v2] + d1)
    return distResults


sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    graph = empty((N + 1, N + 1), dtype=int)
    graph.fill(INF)

    row = map(int, raw_input().split())
    hotels = set(row[1:])

    M = int(input())
    for i in range(M):
        row = map(int, raw_input().split())
        graph[row[0], row[1]] = row[2]
        graph[row[1], row[0]] = row[2]

    hotels = list(hotels) + [0, 1, N]
    hLen = len(hotels)
    hotels.sort()
    hotelGraph = zeros(((hLen + 1), (hLen + 1)), dtype=int)
    for i, h1 in enumerate(hotels):
        hDist = dijkstra(h1)
        for j, h2 in enumerate(hotels):
            if hDist[h2] <= 600:
                hotelGraph[i, j] = 1

    # bfs
    dist = [INF] * (hLen)
    dist[1] = 0
    q = deque()
    q.append(1)
    while q:
        v1 = q.popleft()
        for v2 in range(1, hLen):
            if hotelGraph[v1, v2] and dist[v2] == INF:
                q.append(v2)
                dist[v2] = dist[v1] + 1
    if dist[-1] == INF:
        print -1
    else:
        print dist[-1] - 1
