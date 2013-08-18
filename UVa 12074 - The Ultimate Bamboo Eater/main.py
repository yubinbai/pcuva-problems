'''
Created on Jul 11, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, array = par
    array = sorted(array, key=lambda x: x[2])
    array.reverse()
    array[0].append(1)
    for i in range(1, N):
        currMax = 1
        for j in range(i - 1, -1, -1):
            if array[j][-1] + 1 <= currMax:
                continue
            dist = abs(array[i][0] - array[j][0]) +\
                abs(array[i][1] - array[j][1])
            if dist <= array[j][3]:
                currMax = array[j][-1] + 1
        array[i].append(currMax)
    return max(e[-1] for e in array)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            N = int(self.fIn.readline())
            array = []
            for i in range(N):
                array.append(map(int, self.fIn.readline().split()))
            self.input.append((N, array))

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
