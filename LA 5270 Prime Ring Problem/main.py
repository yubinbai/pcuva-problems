'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31

Primes = set([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37])


def solve(par):
    def fill(step):
        if step == N - 1:
            for i in range(2, N + 1):
                if i not in ring and i + 1 in Primes:
                    ring.append(i)
                    results.append(tuple(ring))
                    ring.pop()
            return
        for i in range(2, N + 1):
            if i not in ring and i + ring[-1] in Primes:
                ring.append(i)
                fill(step + 1)
                ring.pop()

    N = par
    ring = [1]
    results = []
    fill(1)
    for i in range(len(results)):
        results[i] = ' '.join(str(e) for e in results[i])
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            line = self.fIn.readline().strip()
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
            self.fOut.write("%s\n" % self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
