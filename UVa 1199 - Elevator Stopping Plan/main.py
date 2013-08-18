'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    stopPlan = [None]

    def valid(t):
        f = []
        for a in array:
            if (a - 1) * 20 <= t:
                continue
            if not f:
                f.append(a)
                if (a - 1) * 4 > t:
                    return False
                continue
            t1 = abs(a - f[-1]) * 20 + (f[-1] - 1) * 4 + (len(f) - 1) * 10
            if t1 > t:
                f.append(a)
                if (a - 1) * 4 + (len(f) - 1) * 10 > t:
                    return False
        stopPlan[0] = '%d %s' % (len(f), ' '.join(str(e) for e in f))
        return True

    N, array = par
    array.sort()
    low, high = 0, 410
    while low < high - 1:
        mid = (low + high) >> 1
        if valid(mid):
            high = mid
        else:
            low = mid

    return '%d\n%s' % (high, stopPlan[0])


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            row = map(int, line.split())
            if row[0] == 0:
                break
            self.numOfTests += 1
            self.input.append((row[0], row[1:]))

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
