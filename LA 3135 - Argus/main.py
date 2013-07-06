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
    queries, k = par
    heap = []
    for q in queries:
        heappush(heap, [q[1], q[0], q[1]])

    results = []
    for i in range(k):
        q = heappop(heap)
        results.append(q[1])
        q[0] += q[2]
        heappush(heap, q)
    return '\n'.join(str(e) for e in results)


class Solver:

    def getInput(self):
        self.numOfTests = 1
        self.input = []
        queries = []
        while True:
            line = self.fIn.readline().strip()
            if line == '#':
                break
            row = map(int, line.split()[1:])
            queries.append(row)
        k = int(self.fIn.readline())
        self.input.append((queries, k))

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
