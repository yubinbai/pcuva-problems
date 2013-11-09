import sys
import numpypy as np
from collections import defaultdict
from collections import deque


def topoSort(graph):
    def topoVisit(u):
        visited[u] = 1
        for v in graph[u]:
            if (visited[v] == 0):
                topoVisit(v)
        topoSorted.appendleft(u)  # this is the only change
    visited = {}
    for v in graph:
        visited[v] = 0
    topoSorted = deque()
    for v in graph:
        if visited[v] == 0:
            topoVisit(v)
    return topoSorted

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    sList = []
    while True:
        line = raw_input().strip()
        if line == '#':
            break
        sList.append(line)
    st = {}
    for i in range(1, len(sList)):
        s1 = sList[i - 1]
        s2 = sList[i]
        for k in range(min(len(s1), len(s2))):
            if s1[k] != s2[k]:
                if s1[k] not in st:
                    st[s1[k]] = []
                if s2[k] not in st:
                    st[s2[k]] = []
                st[s1[k]].append(s2[k])
                break
    print ''.join(topoSort(st))
