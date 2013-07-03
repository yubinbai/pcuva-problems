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
    number = par
    seconds24 = 0.0
    hh = int(number[:2])
    mm = int(number[2:4])
    ss = int(number[4:6])
    cc = int(number[6:])
    seconds24 = hh * 3600 + mm * 60 + ss + cc * 0.01
    seconds10 = seconds24 / 86400.0 * 1E5
    centi10 = int(seconds10 * 100)
    cc = centi10 % 100 + 100
    centi10 /= 100
    ss = centi10 % 100 + 100
    centi10 /= 100
    mm = centi10 % 100 + 100
    centi10 /= 100
    h = centi10 % 10 + 10

    return str(h)[-1] + str(mm)[-2:] + str(ss)[-2:] + str(cc)[-2:]


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            if line == '':
                break
            self.numOfTests += 1
            self.input.append(line)

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
