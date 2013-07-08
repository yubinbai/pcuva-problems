'''
Created on Jul 6, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, setA, setB = par
    parent = {}
    rank = {}
    for a in setA:
        parent[a] = a
    for b in setB:
        parent[b] = b

    def find(i):
        if parent[i] != i:
            parent[i] = find(parent[i])
        return parent[i]

    def union(i, j):
        p1 = find(i)
        p2 = find(j)
        if p1 in set('ABCD'):
            if p2 in set('ABCD'):
                if p1 != p2:
                    return False
            else:
                parent[p2] = p1
        if p2 in set('ABCD'):
            parent[p1] = p2
        return True

    for i in range(N):
        if find(setA[i]) != find(setB[i]):
            r = union(setA[i], setB[i])
            if not r:
                return 'NO'
    result = []
    for p, v in parent.items():
        if p != v and v in set('ABCD'):
            result.append(p + ' ' + v)
    result.sort()
    return 'YES\n' + '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline().strip())
            if N == 0:
                break
            self.numOfTests += 1
            setA = []
            for i in range(N):
                setA.append(self.fIn.readline().strip())
            setB = []
            for i in range(N):
                setB.append(self.fIn.readline().strip())
            self.input.append((N, setA, setB))

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
