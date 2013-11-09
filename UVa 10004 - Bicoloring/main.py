import sys
from collections import deque
from numpypy import *

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    M = int(input())
    graph = zeros((N, N), dtype=byte)
    color = [-1] * N
    edges = []
    for i in range(M):
        row = map(int, raw_input().split())
        edges.append(tuple(row))
        graph[row[0], row[1]] = 1
        graph[row[1], row[0]] = 1

    q = deque([0])
    color[0] = 0
    flag = True
    while q:
        v1 = q.popleft()
        for v2 in range(N):
            if not graph[v1, v2]:
                continue
            if color[v2] == -1:
                color[v2] = color[v1] ^ 1
                q.append(v2)
            elif color[v1] == color[v2]:
                flag = False
                break
        if not flag:
            break

    if flag:
        print('BICOLORABLE.')
    else:
        print('NOT BICOLORABLE.')
