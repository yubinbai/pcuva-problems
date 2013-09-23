import sys
from collections import Counter


def find(i):
    if parent[i] != i:
        parent[i] = find(parent[i])
    return parent[i]


def union(i, j):
    p1 = i
    while parent[p1] != p1:
        p1 = parent[p1]
    p2 = j
    while parent[p2] != p2:
        p2 = parent[p2]
    if rank[p1] < rank[p2]:
        parent[p1] = p2
    else:
        parent[p2] = p1
        if rank[p1] == rank[p2]:
            rank[p1] += 1

sys.stdin = open('input.txt')
while True:
    try:
        N, R = map(int, raw_input().split())
    except:
        break
    deg = [0] * N

    parent = list(range(N))
    rank = [0] * N

    for i in range(R):
        v1, v2 = map(int, raw_input().split())
        deg[v1] += 1
        deg[v2] += 1
        union(v1, v2)
    counter = Counter(parent)
    if all(deg[i] % 2 == 0 for i in range(N)) and len(counter) == 1:
        print 'Possible'
    else:
        print 'Not Possible'
