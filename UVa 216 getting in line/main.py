import sys
from math import hypot
from numpypy import *
from itertools import permutations
INF = 1 << 30

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    dist = zeros((N, N))
    coord = []
    for i in range(N):
        coord.append(map(int, raw_input().split()))
    for i in range(N):
        for j in range(i + 1, N):
            dist[i, j] = dist[j, i] = hypot(
                coord[i][0] - coord[j][0], coord[i][1] - coord[j][1])
    result, resultT = INF, None
    for t in permutations(range(N)):
        total = 0
        for i in range(1, N):
            total += dist[t[i - 1], t[i]] + 16
        if total < result:
            result = total
            resultT = t
    for i in range(1, N):
        print 'Cable requirement to connect %s to %s is %.2f feet.' % (
            coord[resultT[i - 1]], coord[resultT[i]], dist[resultT[i - 1], resultT[i]] + 16)
    print '%.2f' % result
