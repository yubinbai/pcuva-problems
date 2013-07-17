'''
Created on Jul 16, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from math import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    P, Q, R, S, T, U = par

    def fun(x):
        return P * exp(-1.0 * x) + Q * sin(x) + R * cos(x) +\
            S * tan(x) + T * x ** 2 + U
    if fun(1) * fun(0) > 0:
        return 'No solution!'
    epi = 1E-5
    if fun(1.0) > fun(0.0):
        high, low = 1.0, 0.0
    else:
        high, low = 0.0, 1.0

    while abs(high - low) > epi:
        mid = (low + high) / 2.0
        f = fun(mid)
        if f > 0:
            high = mid
        elif f < 0:
            low = mid
    return '%.4f' % mid


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            line = line.strip()
            if line == '':
                break
            self.numOfTests += 1
            P, Q, R, S, T, U = map(float, line.split())
            self.input.append((P, Q, R, S, T, U))

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
