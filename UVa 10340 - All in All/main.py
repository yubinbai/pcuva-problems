'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    memo = {}

    def lcs(i, j):
        if (i, j) in memo:
            return memo[(i, j)]
        if i == -1 or j == -1:
            return 0
        if s[i] == t[j]:
            v = 1 + lcs(i - 1, j - 1)
        else:
            v1 = lcs(i - 1, j)
            v2 = lcs(i, j - 1)
            v = max(v1, v2)
        memo[(i, j)] = v
        return v

    s, t = par
    N = len(s)
    M = len(t)
    if lcs(N - 1, M - 1) == N:
        return 'Yes'
    return 'No'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            line.strip()
            if line == '':
                break
            self.numOfTests += 1
            row = line.split()
            self.input.append(tuple(row))

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
