from collections import defaultdict
import sys


def topoSort(nodes, graph):
    visited = {}
    result = []
        # this vector stores topological sort in reverse order
    for v in nodes:
        visited[v] = 0

    def topoVisit(u):
        visited[u] = 1
        for v in graph[u]:
            if not visited[v]: 
                topoVisit(v)
        result.append(u)  # this is the only change

    for v in nodes:
        if not visited[v]:
            topoVisit(v)
    result.reverse()
    print(' '.join([str(e) for e in result]))

sys.stdin = open('input.txt')
while True:
    n, m = map(int, raw_input().split())
    if n == 0 and m == 0:
        break
    graph = defaultdict(list)
    nodes = list(range(1, n + 1))
    for i in range(m):
        v1, v2 = map(int, raw_input().split())
        graph[v1].append(v2)
    # print graph
    topoSort(nodes, graph)
