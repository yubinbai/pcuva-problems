'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    T, R, H, priceT, validT, priceR, validR, priceH, validH = par
    minT, minR, minH, minP = -1, -1, -1, INF
    for t in range(T):
        for r in range(R):
            for h in range(H):
                if validT[t][r] or validR[r][h] or validH[h][t]:
                    continue
                s = sum([priceT[t], priceR[r], priceH[h]])
                if s < minP:
                    minT, minR, minH, minP = t, r, h, s
    if minP == INF:
        return 'Don\'t get married!'
    else:
        return '%d %d %d:%d' % (minT, minR, minH, minP)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            line = self.fIn.readline().strip()
            if line == '':
                break
            self.numOfTests += 1
            T, R, H = map(int, line.split())
            priceT = []
            validT = []
            for i in range(T):
                row = map(int, self.fIn.readline().split())
                priceT.append(row[0])
                validT.append(row[1:])
            priceR = []
            validR = []
            for i in range(R):
                row = map(int, self.fIn.readline().split())
                priceR.append(row[0])
                validR.append(row[1:])
            priceH = []
            validH = []
            for i in range(H):
                row = map(int, self.fIn.readline().split())
                priceH.append(row[0])
                validH.append(row[1:])
            self.input.append(
                (T, R, H, priceT, validT, priceR, validR, priceH, validH))

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
