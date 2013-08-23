import sys
from numpypy import *
MAXN = 51

sys.stdin = open('input.txt')
numTest = int(input())
graph = zeros((MAXN, MAXN), dtype=int)
for itertest in range(numTest):
    graph.fill(0)
    N = int(input())
    for i in range(N):
        x, y = map(int, raw_input().split())
        graph[x, y] += 1
        graph[y, x] += 1
    oddV = []
    for i in range(MAXN):
        s = sum([graph[i, j] for j in range(MAXN)])
        if s % 2:
            oddV.append(i)
    print 'Case #%d' % (itertest + 1)
    if len(oddV) > 0:
        print 'No solution'
    else:
        path = []
        curr = x
        for c in range(N):
            for i in range(MAXN):
                if graph[curr, i]:
                    path.append((curr, i))
                    graph[curr, i] -= 1
                    graph[i, curr] -= 1
                    curr = i
        for p in path:
            print '%d %d' % p
