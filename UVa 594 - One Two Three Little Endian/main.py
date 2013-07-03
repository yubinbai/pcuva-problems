''' Created on 2013-6-6

@author: Yubin Bai
'''
import time
import struct
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    number = par
    return struct.unpack('<i', struct.pack('>i', number))[0]


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            if line == '':
                break
            self.numOfTests += 1
            self.input.append(int(line))

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
            self.fOut.write("Case#%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
