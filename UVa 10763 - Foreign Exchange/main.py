'''
Created on Jul 18, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, array1, array2 = par
    array1.sort()
    array2.sort()
    for i in range(N):
        if array1[i] != array2[i]:
            return 'No'
    return 'Yes'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            array1 = []
            array2 = []
            for i in range(N):
                row = map(int, self.fIn.readline().split())
                array1.append(row[0])
                array2.append(row[1])
            self.input.append((N, array1, array2))

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
