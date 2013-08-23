import sys
from itertools import permutations
from math import sqrt


def size(perm):
    currX = perm[0]
    N = len(perm)
    path = [currX]
    for i in range(1, N):
        currX = path[-1]
        for j in reversed(range(i)):
            hDiff = abs(perm[i] - perm[j])
            currX = max(currX, path[j] + sqrt(
                (perm[i] + perm[j]) ** 2 - hDiff ** 2))
        currX = max(currX, perm[i])
        path.append(currX)
    return max(path[i] + perm[i] for i in range(N))

INF = 1 << 30
sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = map(float, raw_input().split())
    radii = line[1:]
    result = min(size(perm) for perm in permutations(radii))
    print '%.3f' % result
