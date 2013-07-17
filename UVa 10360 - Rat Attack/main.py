'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    d, N, rats = par
    grid = []
    for i in range(1025):
        grid.append([0] * 1025)

    for r in rats:
        for x in range(r[0] - d, r[0] + d + 1):
            for y in range(r[1] - d, r[1] + d + 1):
                if x in range(1025) and y in range(1025):
                    grid[x][y] += r[2]

    maxX, maxY, currMax = -1, -1, -1
    for x in range(1025):
        for y in range(1025):
            if grid[x][y] > currMax:
                maxX, maxY, currMax = x, y, grid[x][y]

    return '%d %d %d' % (maxX, maxY, currMax)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            d = int(self.fIn.readline())
            N = int(self.fIn.readline())
            rats = []
            for i in range(N):
                rats.append(map(int, self.fIn.readline().split()))
            self.input.append((d, N, rats))

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
