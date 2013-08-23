import sys
from numpypy import *

sys.stdin = open('input.txt')
MAXN = 26
graph = zeros((MAXN, MAXN), dtype=byte)
while True:
    try:
        line = raw_input().strip().split()
    except:
        break
    nodes = [ord(c) - ord('a') for c in line]
    nodes.sort()
    relations = raw_input().strip().split()
    N = len(relations) / 2
    graph.fill(0)
    for i in range(N):
        graph[ord(relations[i * 2 + 1]) - ord('a'),
              ord(relations[i * 2]) - ord('a')] = 1
    for k in range(MAXN):
        for i in range(MAXN):
            for j in range(MAXN):
                graph[i, j] |= (graph[i, k] & graph[k, j])
    N = len(nodes)
    path = []
    used = [False] * N

    def perm(step):
        if step == N:
            print ''.join(chr(p + ord('a')) for p in path)
            return
        for i in range(N):
            if not used[i] and (step == 0 or all([graph[p, nodes[i]] == 0 for p in path])):
                path.append(nodes[i])
                used[i] = True
                perm(step + 1)
                path.pop()
                used[i] = False

    perm(0)
