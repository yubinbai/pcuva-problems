'''
Created on Jul 28, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
from numpypy import *
from bitstring import *
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, board = par
    visited = zeros((N, N), dtype=int)

    def floodfill(i, j, color):
        neighbors = [(i - 1, j - 1), (i - 1,  j), (i - 1, j + 1),
                     (i, j - 1), (i, j + 1), (i + 1, j - 1),
                     (i + 1,  j), (i + 1, j + 1)]

        visited[i, j] = color

        for i1, j1 in neighbors:
            if i1 in range(N) and j1 in range(N) and board[i1][j1]\
                    and visited[i1, j1] == 0:
                floodfill(i1, j1, color)

    color = 1
    for i in range(N):
        for j in range(N):
            if visited[i, j] == 0 and board[i][j]:
                floodfill(i, j, color)
                color += 1
    return 'Image contains %d war eagles.' % (color - 1)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            try:
                N = int(self.fIn.readline())
            except:
                break
            self.numOfTests += 1
            board = []
            for i in range(N):
                board.append(BitArray('0b' + self.fIn.readline().strip()))
            self.input.append((N, board))

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
            self.fOut.write("%d %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()
if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
