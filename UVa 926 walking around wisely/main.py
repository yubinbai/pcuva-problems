import sys
from numpypy import *

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    connected = ones((N + 1, N + 1, N + 1, N + 1), dtype=byte)
    startX, startY = map(int, raw_input().split())
    endX, endY = map(int, raw_input().split())
    w = int(input())
    for i in range(w):
        line = raw_input().split()
        x, y = int(line[0]), int(line[1])
        if line[2] == 'E':
            connected[x, y, x + 1, y] = 0
        elif line[2] == 'W':
            connected[x - 1, y, x, y] = 0
        elif line[2] == 'N':
            connected[x, y, x, y + 1] = 0
        elif line[2] == 'S':
            connected[x, y - 1, x, y] = 0
    if startX > endX or startY > endY:
        print 0
        continue
    result = zeros((N + 1, N + 1), dtype=byte)
    result[startX, startY] = 1
    for x in range(startX, endX + 1):
        for y in range(startY, endY + 1):
            if connected[x - 1, y, x, y]:
                result[x, y] += result[x - 1, y]
            if connected[x, y - 1, x, y]:
                result[x, y] += result[x, y - 1]
    print result[endX, endY]
