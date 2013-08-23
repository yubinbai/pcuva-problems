import sys
from itertools import combinations
from collections import defaultdict
from collections import deque
from copy import deepcopy
INF = 1 << 30
MAXN = 1005


def edmondsKarp(graph, s, t):

    def augmentPath(v, minEdge):
        if (v == s):  # managed to get back to source
            f[0] = minEdge  # minEdge of the path
            return
        elif (v in p):  # augment if there is a path
            # we need AdjMat for fast lookup here
            augmentPath(p[v], min(minEdge, graph[p[v]][v]))
            graph[p[v]][v] -= f[0]  # forward edges -> decrease
            graph[v][p[v]] += f[0]  # backward edges -> increase

    p = {}  # parent map to reconstruct path
    f = [0]  # global variables, use list as mutable

    max_flow = 0
    while True:  # this will be run max O(VE) times
        f[0] = 0
        q = deque()
        dist = {s: 0}  # O(E) BFS and record path p
        q.append(s)
        while q:
            u = q.popleft()  # queue: layer by layer!
            if (u == t):
                break  # modification 1: reach sink t, stop BFS
            for v in graph[u]:  # for each neighbors of u
                # modification 2: also check AdjMat as edges may disappear
                if graph[u][v] > 0 and v not in dist:
                    dist[v] = dist[u] + 1  # then v is reachable from u
                    q.append(v)  # enqueue v for next steps
                    p[v] = u  # modification 3: parent of v->first is u

        augmentPath(t, INF)  # path augmentation in O(V)
        if (f[0] == 0):
            break  # seems that we cannot pass any more flow
        max_flow += f[0]
    return max_flow

sys.stdin = open('input.txt')
while True:
    nk, np = map(int, raw_input().split())
    if not nk:
        break
    graph = defaultdict(dict)  # combination of adj list and adj matrix
    line = map(int, raw_input().split())
    totalFlow = sum(line)
    SINK = MAXN * 2
    SOURCE = MAXN * 3
    for i, v in enumerate(line):
        graph[i + MAXN][SINK] = v
        graph[SINK][i + MAXN] = 0
    for i in range(np):
        graph[SOURCE][i] = 1
        graph[i][SOURCE] = 0
        line = map(int, raw_input().split())
        for j in line[1:]:
            graph[i][j + MAXN - 1] = 1
            graph[j + MAXN - 1][i] = 0

    originalGraph = deepcopy(graph)
    flow = edmondsKarp(graph, SOURCE, SINK)
    if flow == totalFlow:
        print 1
        for j in range(nk):
            for i in range(np):
                if j + MAXN in originalGraph[i] and \
                        originalGraph[i][j + MAXN] and\
                        not graph[i][j + MAXN]:
                    print i + 1,
            print
    else:
        print 0
