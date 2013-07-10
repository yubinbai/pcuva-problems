'''
Created on Jul 7, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from itertools import combinations
from math import sqrt
from heapq import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    def mst():

        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]

        def union(i, j):
            p1 = find(i)
            p2 = find(j)
            if rank[p1] < rank[p2]:
                parent[p1] = p2
            else:
                parent[p2] = p1
                if rank[p1] == rank[p2]:
                    rank[p1] += 1

        # make disjoint set
        parent = range(P)
        rank = [0] * P
        # kruskal
        heapify(graph)
        mst = []
        while len(mst) < P - S:
            c, start, end = heappop(graph)
            if find(start) != find(end):
                mst.append(c)
                union(start, end)
        return max(mst)

    S, P, stations = par
    graph = []
    for s1, s2 in combinations(range(P), 2):
        d = (stations[s1][0] - stations[s2][0]) ** 2 + (
            stations[s1][1] - stations[s2][1]) ** 2
        graph.append([sqrt(d), s1, s2])

    return '%.2f' % mst()


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            S, P = map(int, self.fIn.readline().split())
            stations = []
            for i in range(P):
                stations.append(map(float, self.fIn.readline().split()))
            self.input.append((S, P, stations))

    def __init__(self):
        self.fIn = open('input.txt')
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
            self.fOut.write("%s\n" % self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
