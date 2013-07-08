'''
Created on Jul 6, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):

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

    last, edges = par
    # make disjoint set
    parent = {}
    chars = [chr(e) for e in range(ord('A'), ord(last) + 1)]
    for i in chars:
        parent[i] = i
    rank = {}
    for i in chars:
        rank[i] = 0

    for e in edges:
        if find(e[0]) != find(e[1]):
            union(e[0], e[1])
    counter = Counter(parent.values())
    return len(counter)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        self.fIn.readline()
        for i in range(self.numOfTests):
            last = self.fIn.readline().strip()
            edges = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                edges.append(line)
            self.input.append((last, edges))

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
