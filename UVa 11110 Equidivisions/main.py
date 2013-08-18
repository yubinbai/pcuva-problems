import sys
from numpypy import *


def testColor(color, count):
    def fillColor(i, j, c):
        directions = [(i, j - 1), (i, j + 1), (i + 1, j), (i - 1, j)]
        for i1, j1 in directions:
            if i1 > 0 and i1 <= n and j1 > 0 and j1 <= n\
                    and graph[i1, j1] == c and not visited[i1, j1]:
                visited[i1, j1] = 1
                cCount[0] += 1
                fillColor(i1, j1, c)
    cCount = [1]
    flag = False
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if graph[i, j] == color:
                visited[i, j] = 1
                fillColor(i, j, color)
                flag = True
                break
        if flag:
            break
    return cCount[0] == count


sys.stdin = open('input.txt')
while True:
    n = int(input())
    if n == 0:
        break
    graph = zeros((n + 1, n + 1), dtype=byte)
    visited = zeros((n + 1, n + 1), dtype=byte)
    colorCounts = []
    for i in range(n - 1):
        row = map(int, raw_input().split())
        colorCounts.append(len(row) // 2)
        for j in range(len(row) // 2):
            graph[row[j * 2], row[j * 2 + 1]] = i + 1
    print graph
    flag = True
    for i in range(n - 1):
        if not testColor(i + 1, colorCounts[i]):
            flag = False
            break
    if flag:
        print 'good'
    else:
        print 'wrong'
