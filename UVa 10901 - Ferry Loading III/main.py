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
    n, t, m, cars = par
    leftQ = []
    rightQ = []
    for i, c in enumerate(cars):
        if c[1] == 'left':
            leftQ.append(i)
        else:
            rightQ.append(i)
    atLeft = True
    currT = 0
    while leftQ or rightQ:
        next = INF
        if leftQ and rightQ:
            next = min(cars[leftQ[0]][0], cars[rightQ[0]][0])
        elif leftQ:
            next = cars[leftQ[0]][0]
        elif rightQ:
            next = cars[rightQ[0]][0]
        currT = max(currT, next)
        counter = 0
        if atLeft:
            while leftQ and leftQ[0] <= currT and counter < n:
                cars[leftQ[0]].append(currT + t)
                counter += 1
                del leftQ[0]
        else:
            while rightQ and rightQ[0] <= currT and counter < n:
                cars[rightQ[0]].append(currT + t)
                counter += 1
                del rightQ[0]
        currT += t
        atLeft = not atLeft
    result = [e[2] for e in cars]
    return '\n'.join(str(e) for e in result) + '\n'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            n, t, m = map(int, self.fIn.readline().split())
            cars = []
            for i in range(m):
                row = self.fIn.readline().split()
                cars += [[int(row[0]), row[1]]]
            self.input.append((n, t, m, cars))

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
