'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def solve(par):
    N, M = par
    left = 0, 1
    right = 1, 0
    result = []

    def search(left, right):
        mid = (left[0] + right[0]), (left[1] + right[1])
        g = gcd(mid[1], M)
        l = mid[1] * M / g
        midValue = l / mid[1] * mid[0]
        nValue = l / M * N
        if nValue > midValue:
            result.append('R')
            search(mid, right)
        elif nValue < midValue:
            result.append('L')
            search(left, mid)

    search(left, right)
    return ''.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, M = map(int, self.fIn.readline().split())
            if N == 1:
                break
            self.numOfTests += 1
            self.input.append((N, M))

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
