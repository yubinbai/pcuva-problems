import sys
from math import sqrt, floor
from itertools import combinations

INF = 1 << 30
sys.stdin = open('input.txt')
trees = []
counter = [0] * 10

while True:
    line = map(int, raw_input().split())
    if line == [0, 0, 0]:
        N = len(trees)
        clowsest = [INF] * N
        for i in range(N):
            for j in range(i + 1, N):
                d = sqrt((trees[i][0] - trees[j][0]) ** 2 +
                        (trees[i][1] - trees[j][1]) ** 2 +
                        (trees[i][2] - trees[j][2]) ** 2)
                clowsest[i] = min(clowsest[i], d)
                clowsest[j] = min(clowsest[j], d)
        for c in clowsest:
            f = int(floor(c))
            if f < 10:
                counter[f] += 1
        print counter
        break
    else:
        trees.append(list(line))
