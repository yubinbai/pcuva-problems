'''
Created on Jul 2, 2013
@author: Yubin Bai
All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):

    def match(c1, c2):
        return c1[0] == c2[0] or c1[1] == c2[1]

    deck = par
    piles = []
    for c in deck:
        piles.append([c])

    isMoved = True
    while isMoved:
        isMoved = False
        P = list(piles)
        for i, p in enumerate(P):
            if i - 3 >= 0 and match(p[-1], piles[i - 3][-1]):
                piles[i - 3].append(p.pop())
                isMoved = True
                if len(p) == 0:
                    del piles[i]
                break
            if i - 1 >= 0 and match(p[-1], piles[i - 1][-1]):
                piles[i - 1].append(p.pop())
                isMoved = True
                if len(p) == 0:
                    del piles[i]
                break

    result = [len(p) for p in piles]
    return ('%d piles remaining' % len(result)) + ' ' + ' '.join(str(e) for e in result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []

        while True:
            deck = self.fIn.readline().split()
            if deck[0] == '#':
                break
            self.numOfTests += 1
            deck += self.fIn.readline().split()
            self.input.append((deck))

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
