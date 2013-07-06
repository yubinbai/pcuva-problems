'''
Created on Jul 5, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from bintrees import RBTree
parallelSolve = False
INF = 1 << 31


def solve(par):
    n, days = par
    urn = RBTree()
    cost = 0
    for d in days:
        for bill in d:
            try:
                urn[bill] += 1
            except:
                urn[bill] = 1
        if urn.count >= 2:
            m1, v1 = urn.max_item()
            m2, v2 = urn.min_item()
            if v1 == 1:
                urn.discard(m1)
            else:
                urn[m1] = v1 - 1
            if v2 == 1:
                urn.discard(m2)
            else:
                urn[m2] = v2 - 1
            cost += m1 - m2
    return cost


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            n = int(self.fIn.readline())
            if n == 0:
                break
            self.numOfTests += 1
            days = []
            for i in range(n):
                days.append(map(int, self.fIn.readline().split())[1:])
            self.input.append((n, days))

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
