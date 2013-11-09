import sys
from collections import defaultdict


def getSeparation(graph):
    def dfs(u):
        dfsLowpoint[u] = dfsNumber[u] = dfsNumberCounter[0]
            # dfsLowpoint[u] <= dfsNumber[u]
        dfsNumberCounter[0] += 1
        for v in graph[u]:
            if (dfsNumber[v] == 0):  # a tree edge
                dfsParent[v] = u  # parent of this children is me
                if (u == dfsRoot):  # special case
                    rootChildren[0] += 1  # count children of root
                dfs(v)
                if (dfsLowpoint[v] >= dfsNumber[u]):  # for articulation point
                    cutPoints[
                        u] = True  # store this information first
                if (dfsLowpoint[v] > dfsNumber[u]):  # for bridge
                    # print("Edge (%d, %d) is a bridge" % (u, v))
                    dfsLowpoint[u] = min(
                        dfsLowpoint[u], dfsLowpoint[v])  # update dfsLowpoint[u]
            elif (v != dfsParent[u]):  # a back edge and not direct cycle
                dfsLowpoint[u] = min(
                    dfsLowpoint[u], dfsNumber[v])  # update dfsLowpoint[u]
    dfsLowpoint = {}
    dfsNumber = {}
    dfsParent = {}
    cutPoints = {}
    dfsNumberCounter = [1]
    for v in graph:
        cutPoints[v] = False
        dfsNumber[v] = 0
        dfsParent[v] = None

    for v in graph:
        if (dfsNumber[v] == 0):
            dfsRoot = v
            rootChildren = [0]
            dfs(v)
            cutPoints[dfsRoot] = (rootChildren[0] > 1)
    return sum(cutPoints.values())


sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    graph = defaultdict(list)
    for line in iter(raw_input, '0'):
        a = map(int, line.split())
        k = a[0]
        for v in a[1:]:
            graph[k].append(v)
            graph[v].append(k)
    print getSeparation(graph)
