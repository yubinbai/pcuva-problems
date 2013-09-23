import sys


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
numTest = int(input())
for itertest in range(numTest):
    F, E, A, B = map(int, raw_input().split())
    rank = [0] * F
    parent = list(range(F))
    for i in range(E):
        X, Y = map(int, raw_input().split())
        for f in range(Y, F, X):
            union(Y, f)
    if find(A) == find(B):
        print 'It is possible to move the furniture.'
    else:
        print 'The furniture cannot be moved.'
