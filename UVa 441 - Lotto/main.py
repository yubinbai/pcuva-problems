'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from itertools import combinations
parallelSolve = False
INF = 1 << 31


def solve(par):
    comb = par
    result = []
    for c in combinations(comb, 6):
        result.append(' '.join(c))
    return '\n'.join(result) + '\n'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            line = self.fIn.readline().strip().split()
            if line[0] == '0':
                break
            self.numOfTests += 1
            self.input.append(line[1:])

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
