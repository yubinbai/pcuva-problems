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
    N, lines = par
    x = set()
    for l in lines:
        x.add(l[0])
        x.add(l[2])
        if l[0] > l[2]:
            l[0], l[2] = l[2], l[0]
    x = list(x)
    x.sort()
    result = [['-inf', '%.3f' % x[0], '%.3f' % 1.0]]
    for i in range(len(x) - 1):
        curr = 1.0
        for l in lines:
            if x[i] >= l[0] and x[i + 1] <= l[2]:
                curr *= l[4]
        result.append(['%.3f' % x[i], '%.3f' % x[i + 1], '%.3f' % curr])
    result.append(['%.3f' % x[-1], '+inf', '%.3f' % 1.0])

    return '\n'.join(['%s %s %s' % (e[0], e[1], e[2]) for e in result])


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        self.fIn.readline()
        for test in range(self.numOfTests):
            N = int(self.fIn.readline().strip())
            lines = []
            for i in range(N):
                lines.append(map(float, self.fIn.readline().split()))
            self.input.append((N, lines))

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
            self.fOut.write("%s\n" % (self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
