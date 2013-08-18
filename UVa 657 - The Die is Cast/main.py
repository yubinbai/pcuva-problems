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

    def floodfill(i, j, c):
        neighbors = [(i - 1,  j), (i, j - 1), (i, j + 1), (i + 1,  j)]
        color[i, j] = c
        for i1, j1 in neighbors:
            if i1 in range(N) and j1 in range(M) and board[i1][j1] in list('*X')\
                    and not color[i1, j1]:
                floodfill(i1, j1, c)

    def floodfill2(i, j, c):
        neighbors = [(i - 1,  j), (i, j - 1), (i, j + 1), (i + 1,  j)]
        color2[i, j] = c
        for i1, j1 in neighbors:
            if i1 in range(N) and j1 in range(M) and board[i1][j1] == 'X'\
                    and color2[i1, j1] == color[i1, j1]:
                floodfill2(i1, j1, c)
    N, M, board = par
    color = zeros((N, M), dtype=int)
    c = 0
    for i in range(N):
        for j in range(M):
            if color[i, j] == 0 and board[i][j] in list('*X'):
                c += 1
                floodfill(i, j, c)
    diceCounts = [0] * (c + 1)
    color2 = zeros((N, M), dtype=int)
    color2 = color.copy()
    for i in range(N):
        for j in range(M):
            if color2[i, j] == color[i, j] and board[i][j] == 'X':
                c += 1
                diceCounts[color[i, j]] += 1
                floodfill2(i, j, c)

    diceCounts.sort()
    return ' '.join(str(e) for e in diceCounts[1:])


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            M, N = map(int, self.fIn.readline().split())
            if N == 0:
                break
            self.numOfTests += 1
            board = []
            for i in range(N):
                board.append(self.fIn.readline().strip())
            self.input.append((N, M, board))

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
            self.fOut.write("Case#%d %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()
if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
