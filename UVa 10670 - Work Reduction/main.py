'''
Created on Jul 18, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, M, L, agencies = par
    for i in range(L):
        agencies[i][1] = int(agencies[i][1])
        agencies[i][2] = int(agencies[i][2])
        cost = 0
        n1 = N
        while n1 > M:
            if (n1 >> 1) > M and (n1 - (n1 >> 1)) * agencies[i][1] > agencies[i][2]:
                cost += agencies[i][2]
                n1 >>= 1
            else:
                cost += agencies[i][1] * (n1 - M)
                n1 = M
                break
        agencies[i] = [cost] + agencies[i]
    agencies.sort()
    return '\n'.join(str(e[1]) + ' ' + str(e[0]) for e in agencies) + '\n'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            N, M, L = map(int, self.fIn.readline().split())
            agencies = []
            for i in range(L):
                agencies.append(
                    self.fIn.readline().strip().replace(':', ',').split(','))
            self.input.append((N, M, L, agencies))

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
