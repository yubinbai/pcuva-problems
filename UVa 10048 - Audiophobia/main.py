from numpypy import *
import sys

sys.stdin = open('input.txt')
INF = 1 << 30
itertest = 1
while True:
    C, S, Q = map(int, raw_input().split())
    if C == 0:
        break
    graph = zeros((C, C), dtype=int)
    graph.fill(INF)
    for i in range(S):
        a, b, v = map(int, raw_input().split())
        graph[a - 1, b - 1] = graph[b - 1, a - 1] = v
    for k in range(C):
        for i in range(C):
            for j in range(i + 1, C):
                graph[j, i] = graph[i, j] = min(
                    graph[i, j], max(graph[i, k], graph[k, j]))
    if itertest != 1:
        print
    print 'Case #%d' % itertest
    itertest += 1
    for i in range(Q):
        q1, q2 = map(int, raw_input().split())
        q1 -= 1
        q2 -= 1
        if graph[q1, q2] < INF:
            print graph[q1, q2]
        else:
            print 'no path'
