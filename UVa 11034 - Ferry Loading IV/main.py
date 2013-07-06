'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from collections import deque
parallelSolve = False
INF = 1 << 31


def solve(par):
    l, m, cars = par
    atLeft = True
    passes = 0
    while cars:
        emptySpace = l * 100
        if atLeft:
            while cars and cars[0][1] == 'left' and cars[0][0] <= emptySpace:
                emptySpace -= cars[0][0]
                del cars[0]
        else:
            while cars and cars[0][1] == 'right' and cars[0][0] <= emptySpace:
                emptySpace -= cars[0][0]
                del cars[0]
        atLeft = not atLeft
        passes += 1

    return str(passes)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            l, m = map(int, self.fIn.readline().split())
            cars = []
            for i in range(m):
                row = self.fIn.readline().split()
                cars += [[int(row[0]), row[1]]]
            self.input.append((l, m, cars))

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
