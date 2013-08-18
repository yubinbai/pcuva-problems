'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bitstring import Bits
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, K = par
    results = []

    path = []

    def backtrack(step, currK):
        if step == N:
            if currK == K:
                results.append(''.join(path))
            return
        if currK > K:
            return
        path.append('0')
        backtrack(step + 1, currK)
        path.pop()

        path.append('1')
        backtrack(step + 1, currK + 1)
        path.pop()

    backtrack(0, 0)
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        self.fIn.readline()
        for i in range(self.numOfTests):
            N, K = map(int, self.fIn.readline().split())
            self.input.append((N, K))
            self.fIn.readline()

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
