'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    M, pairs = par
    pairs.sort()
    pairs1 = []
    for p in pairs:
        if p[0] >= M or p[1] <= 0:
            continue
        pairs1.append(tuple(p))
    if not pairs1:
        return 0
    pairs = [pairs1[0]]
    left, right = pairs1[0]
    for p in pairs1:
        p1 = pairs[-1]
        if p[0] == p1[0] and p[1] > p[0]:
            pairs.pop()
            pairs.append(p)
        if p[1] > right:
            pairs.append(p)
            right = p[1]
    if right < M:
        return 0
    return '\n'.join('%d %d' % (e[0], e[1]) for e in pairs)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            line = self.fIn.readline().strip()
            M = int(self.fIn.readline())
            pairs = []
            while True:
                pair = map(int, self.fIn.readline().split())
                if pair[0] == 0 and pair[1] == 0:
                    break
                pairs.append(pair)
            self.input.append((M, pairs))

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
            self.fOut.write("%s\n\n" % self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
