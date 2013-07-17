'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, M, startI, startJ, nBeepers, beepers = par
    minCost = [INF]
    path = set()

    def backtrack(step, i, j, cost):
        if cost > minCost:
            return
        if step == nBeepers:
            cost += abs(i - startI) + abs(j - startJ)
            minCost[0] = min(minCost[0], cost)
            return
        for i1, j1 in beepers:
            if (i1, j1) not in path:
                dist = abs(i1 - i) + abs(j1 - j)
                path.add((i1, j1))
                backtrack(step + 1, i1, j1, cost + dist)
                path.remove((i1, j1))

    backtrack(0, startI, startJ, 0)
    return 'The shortest path has length %d' % minCost[0]


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for iterTest in range(self.numOfTests):
            N, M = map(int, self.fIn.readline().strip().split())
            startI, startJ = map(int, self.fIn.readline().strip().split())
            nBeepers = int(self.fIn.readline())
            beepers = []
            for i in range(nBeepers):
                beepers.append(tuple(map(int, self.fIn.readline().split())))
            self.input.append((N, M, startI, startJ, nBeepers, beepers))

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
9
