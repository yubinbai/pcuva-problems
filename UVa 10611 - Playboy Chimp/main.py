'''
Created on Jul 16, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bisect import *
parallelSolve = False
INF = 1 << 31


def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i - 1]
    raise ValueError


def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError


def solve(par):
    N, Q, array, queries = par
    results = []
    for q in queries:
        row = []
        i1, i2 = -1, -1
        try:
            i1 = find_lt(array, q)
        except:
            i1 = 'X'
        row.append(str(i1))
        try:
            i2 = find_gt(array, q)
        except:
            i2 = 'X'
        row.append(str(i2))
        results.append(' '.join(row))
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = 1
        self.input = []
        N = int(self.fIn.readline())
        array = map(int, self.fIn.readline().split())
        Q = int(self.fIn.readline())
        queries = map(int, self.fIn.readline().split())
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
