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
    K, N, M, points = par

    result = []
    for p in points:
        if p[0] == N or p[1] == M:
            result.append('divisa')
        elif p[0] < N:
            if p[1] > M:
                result.append('NO')
            else:
                result.append('SO')
        else:  # p[0] > N
            if p[1] > M:
                result.append('NE')
            else:
                result.append('SE')

    return '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while 1:
            K = int(self.fIn.readline())
            if K == 0:
                break
            self.numOfTests += 1
            N, M = map(int, self.fIn.readline().split())
            points = []
            for i in range(K):
                points.append(map(int, self.fIn.readline().split()))
            self.input.append((K, N, M, points))

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
