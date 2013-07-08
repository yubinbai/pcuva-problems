'''
Created on Jul 7, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from itertools import combinations
from math import sqrt
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):

    def overlap(c1, c2):
        d = sqrt((c1[0] - c2[0]) ** 2 + (c1[1] - c2[1]) ** 2)
        if d > min(c1[2], c2[2]) and d <= c1[2] + c2[2]:
            return True
        else:
            return False

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

    N, circles = par
    parent = list(range(N))
    rank = [0] * N

    for c1, c2 in combinations(range(N), 2):
        if overlap(circles[c1], circles[c2]):
            union(c1, c2)

    counter = Counter(parent)
    return 'The largest component contains {} rings.'.format(max(counter.values()))


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == -1:
                break
            self.numOfTests += 1
            circles = []
            for i in range(N):
                circles.append(map(float, self.fIn.readline().split()))
            self.input.append((N, circles))

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
