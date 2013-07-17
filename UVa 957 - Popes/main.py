'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bisect import bisect
parallelSolve = False
INF = 1 << 31


def solve(par):
    Y, P, popes = par
    left, right, maxP = -1, -1, -1
    for i1, p1 in enumerate(popes):
        if p1 + Y - 1 > popes[-1]:
            break
        i2 = bisect(popes, p1 + Y - 1, lo=i1 + 1, hi=P)
        if i2 - i1 > maxP:
            left, right, maxP = i1, i2 - 1, i2 - i1

    return '%d %d %d' % (maxP, popes[left], popes[right])


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            try:
                Y = int(self.fIn.readline())
            except:
                break
            P = int(self.fIn.readline())
            popes = []
            for i in range(P):
                popes.append(int(self.fIn.readline()))
            self.fIn.readline()
            self.numOfTests += 1
            self.input.append((Y, P, popes))

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
