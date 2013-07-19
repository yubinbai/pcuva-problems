'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, T, M, cars = par
    time = 0
    trips = 0
    capacity = N
    for c in cars:
        if capacity == 0:
            time += T * 2
            trips += 1
            capacity = N
        capacity -= 1
        time = max(time, c)
    if capacity != N:
        trips += 1
        time = max(cars[-1] + T, time)
    return '%d %d' % (time, trips)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            N, T, M = map(int, self.fIn.readline().split())
            cars = []
            for i in range(M):
                cars.append(int(self.fIn.readline()))
            self.input.append((N, T, M, cars))

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
