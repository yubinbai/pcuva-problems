'''
Created on Jul 5, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from heapq import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    def mst():
        # make disjoint set
        parent = []
        for i in range(n + 1):
            parent.append(i)
        rank = [0] * (n + 1)

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

        heapify(graph)
        mst = []
        while len(mst) < n - 1:
            c, start, end = heappop(graph)
            if find(start) != find(end):
                mst.append(c)
                union(start, end)
        return sum(mst)

    n, setT, k, setK, m, setM = par
    cost1 = sum(e[2] for e in setT)

    graph = setK + setM
    for edge in graph:
        edge[0], edge[2] = edge[2], edge[0]

    cost2 = mst()
    return '%d\n%d\n' % (cost1, cost2)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            line = self.fIn.readline().strip()
            if line == '':
                break
            self.numOfTests += 1
            n = int(line)
            setT = []
            for i in range(n - 1):
                setT.append(map(int, self.fIn.readline().split()))
            k = int(self.fIn.readline())
            setK = []
            for i in range(k):
                setK.append(map(int, self.fIn.readline().split()))
            setM = []
            m = int(self.fIn.readline())
            for i in range(m):
                setM.append(map(int, self.fIn.readline().split()))

            self.input.append((n, setT, k, setK, m, setM))

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
