import sys


def bellman_ford(graph, source):
    def relax(u, v):
        d1 = d[u] + graph[u][v]
        if d[v] > d1:
            d[v] = d1
            pre[v] = u
    d = {}
    pre = {}
    for node in graph:
        d[node] = float('Inf')
        pre[node] = None
    d[source] = 0
    for i in range(len(graph) - 1):
        for u in graph:
            for v in graph[u]:
                relax(u, v)
    # check for negative-weight cycles
    for u in graph:
        for v in graph[u]:
            if d[v] > d[u] + graph[u][v]:
                raise 'negative-weight cycle'
    return d, pre

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    for _ in range(int(input())):
        n, m = map(int, raw_input().split())
        w = dict(zip(range(n), [{} for _ in range(n)]))
        for _ in range(m):
            a, b, w1 = map(int, raw_input().split())
            w[a][b] = w1
        try:
            bellman_ford(w, 0)
            print 'not possible'
        except:
            print 'possible'
