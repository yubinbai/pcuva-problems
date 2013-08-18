from numpypy import *
import sys
from collections import deque
INF = 1 << 30
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
    end = []
    for i in range(M):
        end.append((mall2[i * 2], mall2[i * 2 + 1]))
    q = deque()
    dist = empty((MAXN, MAXN), dtype=int)
    dist.fill(INF)
    result = INF
    for t in start:
        q.append(t)
        dist[t[0], t[1]] = 0
    while q:
        currset = set()
        i, j = q.popleft()
        d = dist[i, j]
        q.appendleft((i, j))
        while q:
            i, j = q.popleft()
            if dist[i, j] != d:
                q.appendleft((i, j))
                break
            neighbors = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
            for i1, j1 in neighbors:
                if i1 < MAXN and i1 >= 0 and j1 < MAXN and j1 >= 0 and dist[i1, j1] == INF:
                    currset.add((i1, j1))
        flag = False
        for i, j in currset:
            if (i, j) in end:
                print d + 1
                flag = True
            dist[i, j] = d + 1
            q.append((i, j))
        if flag:
            break
