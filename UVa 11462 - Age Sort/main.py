'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
import bisect
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):

    def countSort(A):
        freq = [0] * 102
        for a in A:
            freq[a] += 1
        B = []
        for i in range(1, 101):
            B.extend([i] * freq[i])
        return B

    N, A = par
    return ' '.join(str(e) for e in countSort(A))


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            A = map(int, self.fIn.readline().split())
            self.input.append((N, A))

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
