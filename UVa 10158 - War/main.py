'''
Created on Jul 7, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):

    def neg(num):
        if num >= N:
            return num % N
        else:
            return num + N

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

    N, cmd = par
    parent = list(range(2 * N))  # friends
    rank = [0] * (2 * N)
    result = []
    for c in cmd:
        command, x, y = c
        if command == 1:
            if find(x) == find(neg(y)):
                result.append(-1)
            else:
                union(x, y)
                union(neg(x), neg(y))
        if command == 2:
            if find(x) == find(y):
                result.append(-1)
            else:
                union(x, neg(y))
                union(neg(x), y)
        if command == 3:
            result.append(int(find(x) == find(y)))
        if command == 4:
            result.append(int(find(x) == find(neg(y))))

    return '\n'.join(str(e) for e in result)


class Solver:

    def getInput(self):
        self.numOfTests = 1
        self.input = []
        cmd = []
        N = int(self.fIn.readline())
        while True:
            row = map(int, self.fIn.readline().split())
            if row[0] == 0:
                break
            cmd.append(row)
        self.input.append((N, cmd))

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
