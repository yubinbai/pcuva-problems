'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):
    cities = par
    mat = []
    for c in cities:
        mat.append(tuple(sorted(c)))
    counter = Counter(mat)
    cost = {}
    for c1 in counter:
        currCost = 0
        for c2 in counter:
            if c1 != c2:
                currCost += counter[c2] * sum(
                    int(c1[i] != c2[i]) for i in range(5))
        cost[c1] = currCost
    minC, currMin = -1, INF
    for c in cost:
        if cost[c] < currMin:
            minC, currMin = c, cost[c]
    i1 = mat.index(minC)
    return i1 + 1


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        cities = []
        while True:
            line = self.fIn.readline().strip().split(',')
            if line[0][0] == 'e':
                self.numOfTests += 1
                self.input.append(cities)
                cities = []
                continue
            if line[0][0] == '#':
                break
            cities.append(line)

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
