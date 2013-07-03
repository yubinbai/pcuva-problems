'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 30


def solve(par):
    W, H, N, subs = par
    board = []
    for i in range(H + 1):
        board.append(list([False] * (W + 1)))

    for s in subs:
        x1, y1, x2, y2 = s
        x1, x2 = min(x1, x2), max(x1, x2)
        y1, y2 = min(y1, y2), max(y1, y2)
        for i in range(y1, y2 + 1):
            for j in range(x1, x2 + 1):
                board[i][j] = True

    counter = 0
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if not board[i][j]:
                counter += 1

    if counter == 1:
        return 'There is one empty spots.'
    elif counter == 0:
        return 'There is no empty spots.'
    else:
        return 'There are %d empty spots.' % counter


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            W, H, N = map(int, self.fIn.readline().split())
            if W == 0:
                break
            self.numOfTests += 1

            subs = []
            for i in range(N):
                subs.append(map(int, self.fIn.readline().split()))
            self.input.append((W, H, N, subs))
            self.fIn.readline()

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
