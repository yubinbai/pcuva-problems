'''
Created on Jun 29, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from math import acos, sqrt
parallelSolve = False
INF = 1 << 30


def solve(par):

    def makeOutput():
        if curr == first:
            results.append('0' + str(first))
        else:
            s1 = str(first)
            s2 = str(curr)
            l = max(len(s1), len(s2))
            i = 1
            while i <= l:
                if s1[-1 * i] == s2[-1 * i]:
                    break
                i += 1
            results.append('0' + s1 + '-' + s2[-1 * i + 1:])

    N, A = par
    results = []
    first = curr = A[0]
    for i in range(1, N):
        if A[i] != curr + 1:
            makeOutput()
            first = curr = A[i]
        else:
            curr = A[i]
    makeOutput()
    return '\n' + '\n'.join(results) + '\n'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            a = []
            for i in range(N):
                a.append(int(self.fIn.readline()))

            self.input.append((N, a))

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
            self.fOut.write("Case #%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
