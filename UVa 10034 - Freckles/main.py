'''
Created on Jul 29, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
import sys
from numpypy import *
from multiprocessing.pool import Pool
from heapq import *
parallelSolve = False
INF = 1 << 31


def solve(par):

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

    N, points = par
    dist = zeros((N, N))
    for i, p1 in enumerate(points):
        for j, p2 in enumerate(points):
            dist[j, i] = dist[i, j] = sqrt(
                (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)
    heap = []
    for i in range(N):
        for j in range(i + 1, N):
            heappush(heap, (dist[i, j], i, j))
    parent = list(range(N))
    rank = [0] * N

    cost = 0.0
    while heap:
        d, i, j = heappop(heap)
        if find(i) != find(j):
            cost += d
            union(i, j)
    return '%.2f' % cost


class Solver:

    def getInput(self):
        self.numOfTests = int(input())
        self.input = []
        for itertest in range(self.numOfTests):
            raw_input()
            N = int(input())
            points = []
            for i in range(N):
                points.append(map(float, raw_input().split()))
            self.input.append((N, points))

    def __init__(self):
        sys.stdin = open('input.txt')
        self.fOut = open('output.txt', 'w')
        self.results = []

    def parallel(self):
        self.getInput()
        p = Pool(4)
        millis1 = int(round(time.time() * 1000))
        self.results = p.map(solve, self.input)
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def sequential(self):
        self.getInput()
        millis1 = int(round(time.time() * 1000))
        for i in self.input:
            self.results.append(solve(i))
        millis2 = int(round(time.time() * 1000))
        print("Time in milliseconds: %d " % (millis2 - millis1))
        self.makeOutput()

    def makeOutput(self):
        for test in range(self.numOfTests):
            self.fOut.write("%d %s\n" % (test + 1, self.results[test]))
        sys.stdin.close()
        self.fOut.close()
if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
