from numpypy import *
import sys
INF = 200

sys.stdin = open('input.txt')
while True:
    line = map(int, raw_input().strip().split())
    if line[0] == 0 and line[1] == 0:
        break
    nodes = list(set(line))
    nodes.sort()
    del nodes[0]
    nNodes = len(nodes)

    graph = zeros((nNodes, nNodes), dtype=int)
    graph.fill(INF)
    n = len(line) / 2 - 1
    for i in range(n):
        x = nodes.index(line[i * 2])
        y = nodes.index(line[i * 2 + 1])
        graph[x, y] = 1
        graph[x, x] = 0
    # floyd
    for k in range(nNodes):
        for i in range(nNodes):
            for j in range(nNodes):
                graph[i, j] = min(graph[i, j], graph[i, k] + graph[k, j])
    total = sum(graph)
    # print graph
    average = total * 1.0 / (nNodes ** 2 - nNodes)
    print 'average length between pages = %.3f clicks' % average
