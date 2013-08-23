import sys
from kuhnMunkres import Munkres
from math import sqrt


def dist(p1, p2):
    return sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    N, M = map(int, raw_input().split())
    line = map(int, raw_input().split())
    pts1 = [(line[i * 2], line[i * 2 + 1]) for i in range(N)]
    line = map(int, raw_input().split())
    pts2 = [(line[i * 2], line[i * 2 + 1]) for i in range(M)]
    costMatrix = []
    for i in range(N - 1):
        row = [0] * M
        costMatrix.append(row)
    for i in range(N - 1):
        for j in range(M):
            p1, p2, p3 = pts1[i], pts2[j], pts1[i + 1]
            if dist(p1, p3) * 2 >= dist(p1, p2) + dist(p2, p3):
                costMatrix[i][j] = -1
    # print costMatrix
    m = Munkres()
    indexes = m.compute(costMatrix)
    total = 0
    for i, j in indexes:
        print pts1[i],
        if costMatrix[i][j] != 0:
            print pts2[j],
        total += costMatrix[i][j]
    print pts1[-1]
    print 'Total cost: %d' % (N - total)
