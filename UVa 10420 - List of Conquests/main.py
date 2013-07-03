'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 30


def solve(par):
    entries = par

    countries = {}
    for e in entries:
        try:
            countries[e[0]] += 1
        except:
            countries[e[0]] = 1
    results = []
    for c in countries:
        results.append([c, countries[c]])
    results.sort()
    resultStr = []
    for row in results:
        resultStr.append(' '.join([str(e) for e in row]))
    return '\n'.join(resultStr)


class Solver:

    def getInput(self):
        self.numOfTests = 1
        self.input = []
        n = int(self.fIn.readline())
        entries = []
        for i in range(n):
            entries.append(self.fIn.readline().split())
        self.input.append(entries)

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
            self.fOut.write(self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
