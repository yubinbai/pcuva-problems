'''
Created on Jul 16, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bisect import bisect_left
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, Q, array, queries = par
    array.sort()
    results = []
    for q in queries:
        i1 = bisect_left(array, q)
        if array[i1] == q:
            results.append('%d found at %d' % (q, i1 + 1))
        else:
            results.append('%d not found' % q)
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, Q = map(int, self.fIn.readline().split())
            if N == 0:
                break
            self.numOfTests += 1
            array = []
            for i in range(N):
                array.append(int(self.fIn.readline()))
            queries = []
            for i in range(Q):
                queries.append(int(self.fIn.readline()))
            self.input.append((N, Q, array, queries))

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
