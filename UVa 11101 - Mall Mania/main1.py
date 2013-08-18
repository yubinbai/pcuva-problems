from numpypy import *
import sys
from collections import deque
INF = 1 << 15
MAXN = 2000

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    mall1 = []
    while len(mall1) < N * 2:
        mall1.extend(map(int, raw_input().split()))
    start = []
    for i in range(N):
        start.append((mall1[i * 2], mall1[i * 2 + 1]))
    M = int(input())
    mall2 = []
    while len(mall2) < M * 2:
        mall2.extend(map(int, raw_input().split()))
    end = set()
    for i in range(M):
        end.add((mall2[i * 2], mall2[i * 2 + 1]))
    q = deque()
    dist = empty((MAXN, MAXN), dtype=int)
    dist.fill(INF)
    result = INF
    for t in start:
        q.append(t)
        dist[t[0], t[1]] = 0
    while q:
        i, j = q.popleft()
        d = dist[i, j]
        flag = False
        neighbors = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
        for i1, j1 in neighbors:
            if i1 < MAXN and i1 >= 0 and j1 < MAXN and j1 >= 0 and dist[i1, j1] == INF:
                if (i1, j1) in end:
                    flag = True
                    print d + 1
                    break
                else:
                    dist[i1, j1] = d + 1
                    q.append((i1, j1))
        if flag:
            break
