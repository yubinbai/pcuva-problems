'''
Created on Jul 13, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    F, R, front, rear = par
    gears = []
    for f in front:
        for r in rear:
            gears.append(1.0 * f / r)
    gears.sort()
    currMax = -1 * INF
    for i in range(len(gears) - 1):
        currMax = max(currMax, gears[i + 1] / gears[i])
    return '%.2f' % currMax


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            row = map(int, self.fIn.readline().strip().split())
            if row[0] == 0:
                break
            self.numOfTests += 1
            F, R = row
            front = map(int, self.fIn.readline().split())
            rear = map(int, self.fIn.readline().split())
            self.input.append((F, R, front, rear))

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
