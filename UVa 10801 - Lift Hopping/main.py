import sys
from heapq import *
from numpypy import *
from itertools import combinations
INF = 1 << 30


def dijkstra(source):
    dist = zeros((nVertices), dtype=int)
    for i in range(nVertices):
        dist[i] = graph[source, i]
    dist[source] = 0
    visited = zeros((nVertices), dtype=byte)
    heap = []
    for i in range(nVertices):
        heappush(heap, (dist[i], i))
    while heap:
        d1, v1 = heappop(heap)
        if d1 == INF:
            break
        if visited[v1]:
            continue
        dist[v1] = d1
        visited[v1] = 1
        for v2 in range(nVertices):
            value = graph[v1, v2] + d1
            if dist[v2] > value:
                dist[v2] = value
                heappush(heap, (value, v2))
    return dist

sys.stdin = open('input.txt')
while True:
    try:
        n, k = map(int, raw_input().split())
    except:
        break
    elevTime = map(int, raw_input().split())
    elevators = []
    for i in range(n):
        elevators.append(map(int, raw_input().split()))

    vertices = []
    for i in range(n):
        for v in elevators[i]:
            vertices.append((i, v))

    nVertices = len(vertices)
    graph = zeros((nVertices, nVertices), dtype=int)
    graph.fill(INF)
    for i in range(nVertices):
        for j in range(i + 1, nVertices):
            if vertices[i][0] == vertices[j][0]:
                elev = vertices[i][0]
                graph[i, j] = graph[j, i] =\
                    elevTime[elev] * abs(vertices[i][1] - vertices[j][1])
            if vertices[i][1] == vertices[j][1]:
                if vertices[i][1] == 0:
                    graph[i, j] = graph[j, i] = 0
                else:
                    graph[i, j] = graph[j, i] = 60
    source = -1
    for i, v in enumerate(vertices):
        if v[1] == 0:
            source = i
            break
    dist = dijkstra(source)
    minDist = INF
    for i in range(nVertices):
        if vertices[i][1] == k:
            minDist = min(minDist, dist[i])
    if minDist == INF:
        print 'IMPOSSIBLE'
    else:
        print int(minDist)
