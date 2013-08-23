from numpypy import *
from itertools import combinations
import sys

sys.stdin = open('input.txt')
itertest = 1
while True:
    NC = int(input())
    if not NC:
        break
    names = []
    computations = []
    for i in range(NC):
        line = raw_input().strip().split()[1:]
        computations.append(list(line))
        names += line
    names = dict((v, k) for k, v in enumerate(names))
    N = len(names)
    graph = zeros((N, N), dtype=byte)
    for c in computations:
        for i in range(len(c) - 1):
            graph[names[c[i]], names[c[i + 1]]] = 1
    for i in range(int(input())):
        e1, e2 = raw_input().strip().split()
        graph[names[e1], names[e2]] = 1
    for k in range(N):
        for i in range(N):
            for j in range(N):
                graph[i, j] |= (graph[i, k] & graph[k, j])
    for i in range(N):
        for j in range(N):
            graph[i, j] |= graph[j, i]
    result = []
    for n1, n2 in combinations(names, 2):
        if not graph[names[n1], names[n2]]:
            result.append((n1, n2))

    if len(result) >= 2:
        print 'Case #%d, %d concurrent events: ' % (itertest, len(result))
        print '(%s, %s)' % result[0], '(%s, %s)' % result[1]
    elif len(result) == 1:
        print 'Case #%d, 1 concurrent event: ' % itertest
        print '(%s, %s)' % result[0]
    else:
        print 'Case #%d, no concurrent events.' % itertest
    itertest += 1
