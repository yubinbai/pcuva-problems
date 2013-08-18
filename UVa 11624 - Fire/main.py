from collections import deque
from numpypy import *
import sys
INF = 1 << 30

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    R, C = map(int, raw_input().split())
    graph_input = []
    for i in range(R):
        graph_input.append(raw_input().strip())
    graph = zeros((R, C), dtype=int)
    q = deque()
    for i in range(R):
        for j in range(C):
            if graph_input[i][j] == '#':
                graph[i, j] = -1 * INF
            elif graph_input[i][j] == '.':
                graph[i, j] = INF
            elif graph_input[i][j] == 'F':
                graph[i, j] = -1
            elif graph_input[i][j] == 'J':
                graph[i, j] = 0
                q.append((i, j))
    # print graph
    for i in range(R):
        for j in range(C):
            if graph[i, j] == -1:
                q.append((i, j))
    flag = False
    while q:
        i, j = q.popleft()
        moves = [(i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)]
        for i1, j1 in moves:
            if i1 >= R or i1 < 0 or j1 >= C or j1 < 0:
                if graph[i, j] >= 0:
                    flag = True
                    print graph[i, j] + 1
                    break
            else:
                if graph[i1, j1] == INF and graph[i, j] >= 0:
                    q.append((i1, j1))
                    graph[i1, j1] = graph[i, j] + 1
                if graph[i, j] < 0 and graph[i1, j1] >= 0:
                    q.append((i1, j1))
                    graph[i1, j1] = -1
        if flag:
            break
    if not flag:
        print 'IMPOSSIBLE'
