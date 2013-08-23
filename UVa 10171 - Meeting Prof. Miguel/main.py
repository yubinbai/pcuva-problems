from numpypy import *
import sys

sys.stdin = open('input.txt')
INF = 1 << 10
MAXN = 26
youngGraph = zeros((MAXN + 1, MAXN + 1), dtype=int)
oldGraph = zeros((MAXN + 1, MAXN + 1), dtype=int)
while True:
    N = int(input())
    if not N:
        break
    youngGraph.fill(INF)
    oldGraph.fill(INF)
    for i in range(N):
        line = raw_input().strip().split()
        if line[0] == 'Y':
            x = ord(line[2]) - ord('A')
            y = ord(line[3]) - ord('A')
            if line[1] == 'B':
                youngGraph[x, y] = youngGraph[y, x] = int(line[-1])
            else:
                youngGraph[x, y] = int(line[-1])
        else:
            x = ord(line[2]) - ord('A')
            y = ord(line[3]) - ord('A')
            if line[1] == 'B':
                oldGraph[x, y] = oldGraph[y, x] = int(line[-1])
            else:
                oldGraph[x, y] = int(line[-1])
    startY, startO = map(lambda x: ord(x) - ord('A'), raw_input().split())
    for k in range(MAXN):
        for i in range(MAXN):
            for j in range(MAXN):
                youngGraph[i, j] = min(
                    youngGraph[i, j], youngGraph[i, j] + youngGraph[k, j])
                oldGraph[i, j] = min(
                    oldGraph[i, j], oldGraph[i, j] + oldGraph[k, j])
    # print youngGraph
    # print oldGraph
    minDist, minI = INF, -1
    for i in range(MAXN):
        d = youngGraph[startY, i] + oldGraph[startO, i]
        if d < minDist:
            minDist, minI = d, i
    if minDist >= INF:
        print 'You will never meet.'
    else:
        print '%d %s' % (minDist, chr(ord('A') + minI))
