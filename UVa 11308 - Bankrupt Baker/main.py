'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from collections import defaultdict
from itertools import combinations
parallelSolve = False
INF = 1 << 31


def solve(par):
    binderName, m, n, b, ingredients, recipies = par
    ingre = {}
    for row in ingredients:
        ingre[row[0]] = row[1]

    results = []
    for r in recipies:
        req = {}
        for item in r[1]:
            req[item[0]] = item[1]
        cost = sum(req[e] * ingre[e] for e in req)
        if b >= cost:
            results.append(r[0])
    if results:
        return binderName.upper() + '\n' + '\n'.join(results) + '\n'
    else:
        return binderName.upper() + '\n' + 'Too Expensive!'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            binderName = self.fIn.readline().strip()
            m, n, b = map(int, self.fIn.readline().split())
            ingredients = []
            for j in range(m):
                row = self.fIn.readline().split()
                row[1] = int(row[1])
                ingredients.append(row)
            recipies = []
            for it in range(n):
                cakeName = self.fIn.readline().strip()
                k = int(self.fIn.readline())
                requirement = []
                for s in range(k):
                    row = self.fIn.readline().split()
                    row[1] = int(row[1])
                    requirement.append(row)
                recipies.append([cakeName, requirement])
            self.input.append((binderName, m, n, b, ingredients, recipies))

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
