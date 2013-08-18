import sys
from collections import deque
from numpypy import *
INF = 1 << 31

sys.stdin = open('input.txt', 'r')
numTest = int(input())
print('SHIPPING ROUTES OUTPUT')
for itertest in range(numTest):
    M, N, P = map(int, raw_input().split())
    names = raw_input().strip().split()
    number = {}
    for i, n in enumerate(names):
        number[n] = i
    graph = zeros((M, M), dtype=int)
    for i in range(N):
        v1, v2 = raw_input().strip().split()
        graph[(number[v1], number[v2])] = 1
        graph[(number[v2], number[v1])] = 1
    print('\nDATA SET %d\n' % (itertest + 1))
    for i in range(P):
        query = raw_input().strip().split()
        weight = int(query[0])
        start = number[query[1]]
        end = number[query[2]]
        dist = [INF] * M
        dist[start] = 0
        q = deque()
        q.append(start)
        while q:
            v1 = q.popleft()
            for v2 in range(M):
                if v2 != v1 and dist[v2] >= INF and graph[v1, v2]:
                    dist[v2] = dist[v1] + 1
                    q.append(v2)
        if dist[end] < INF:
            print('$%d' % (weight * dist[end] * 100))
        else:
            print('NO SHIPMENT POSSIBLE')
print('\nEND OF OUTPUT')
