import sys
from numpypy import *
from collections import deque

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == -1:
        break
    graph = zeros((N + 1, N + 1), dtype=int)
    for i in range(1, N + 1):
        line = map(int, raw_input().split())
        graph[i, 0] = line[0]
        if line[1] > 0:
            for j in line[2:]:
                graph[i, j] = 1
    energy = [0] * (N + 1)
    q = deque([(1, 100)])
    while q:
        v1, e = q.popleft()
        if energy[v1] > 100 * N and e > energy[v1]:
            continue

        if e > energy[v1]:
            energy[v1] = e
            for v2 in range(1, N + 1):
                if graph[v1, v2]:
                    q.append((v2, e + graph[v2, 0]))
    if energy[N] != 0:
        print 'winnable'
    else:
        print 'hopeless'
