'''
Created on Jul 18, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, M, heads, knights = par
    heads.sort()
    knights.sort()
    i = j = 0
    cost = 0
    counter = 0
    while i < N and j < M:
        if heads[i] <= knights[j]:
            if counter == N:
                break
            cost += knights[j]
            i += 1
            j += 1
            counter += 1
        else:
            j += 1
    if counter < N:
        return 'Loowater is doomed!'
    return cost


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, M = map(int, self.fIn.readline().split())
            if N == 0:
                break
            self.numOfTests += 1
            heads = []
            for i in range(N):
                heads.append(int(self.fIn.readline()))
            knights = []
            for i in range(M):
                knights.append(int(self.fIn.readline()))
            self.input.append((N, M, heads, knights))

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
