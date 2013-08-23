from collections import defaultdict
from collections import deque
import sys


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

INF = 1 << 30
MAXN = 1 << 10
SOURCE = MAXN
SINK = MAXN * 2
sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N, M = map(int, raw_input().split())
    graph = defaultdict(dict)
    for i in range(M):
        graph[SOURCE][i] = 1
        graph[i][SOURCE] = 0
        line = raw_input().strip().split()
        graph[i][line[0]] = 1
        graph[line[0]][i] = 0
        graph[i][line[1]] = 1
        graph[line[1]][i] = 0
    for i in set(['L', 'XL', 'XL', 'L', 'XXL', 'XL', 'S', 'XS', 'M', 'S', 'M', 'L']):
        graph[i][SINK] = N / 6
        graph[SINK][i] = 0
    flow = edmondsKarp(graph, SOURCE, SINK)
    if flow == M:
        print 'YES'
    else:
        print 'NO'
