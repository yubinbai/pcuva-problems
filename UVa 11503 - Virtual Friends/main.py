'''
Created on Jul 8, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    def find(i):
        if parent[i][0] != i:
            parent[i] = find(parent[i][0])
        return parent[i]

    def union(i, j):
        p1 = find(i)
        p2 = find(j)
        parent[p1[0]] = (p2[0], p1[1] + p2[1])
        parent[p2[0]] = (p2[0], p1[1] + p2[1])

    N, comb = par
    # make disjoint set
    parent = {}  # 'key':(parent, number)

    results = []
    for c in comb:
        c1, c2 = c
        if c1 not in parent:
            parent[c1] = (c1, 1)
        if c2 not in parent:
            parent[c2] = (c2, 1)
        union(c1, c2)
        results.append(find(c1)[1])

    return '\n'.join(str(e) for e in results)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            N = int(self.fIn.readline())
            comb = []
            for i in range(N):
                comb.append(self.fIn.readline().split())
            self.input.append((N, comb))

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
