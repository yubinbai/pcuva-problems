'''
Created on Jul 27, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
from numpypy import *
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, board = par
    visited = zeros((N, N), dtype=byte)

    def dfs(i, j, color):
        if j == N - 1 and color == 'w':
            return True
        if i == N - 1 and color == 'b':
            return True
        neighbors = [(i - 1, j - 1), (i - 1,  j),
                     (i, j - 1), (i, j + 1),
                     (i + 1,  j), (i + 1, j + 1)]

        visited[i, j] = True

        for i1, j1 in neighbors:
            if i1 in range(N) and j1 in range(N) and board[i1][j1] == color\
                    and not visited[i1, j1]:
                if dfs(i1, j1, color):
                    return True
        return False
    c = board[0][0]
    if dfs(0, 0, c):
        return c.upper()
    else:
        if c == 'w':
            return 'B'
        else:
            return 'W'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            board = []
            for i in range(N):
                board.append(self.fIn.readline().strip())
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
