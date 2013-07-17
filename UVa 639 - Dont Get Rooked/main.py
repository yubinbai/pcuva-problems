'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, board = par
    maxCount = [0]

    def valid(i, j):
        i1, j1 = i, j
        while i1 - 1 >= 0:
            i1 -= 1
            if board[i1][j1] == 'X':
                break
            if board[i1][j1] == 'o':
                return False
        i1, j1 = i, j
        while i1 + 1 < N:
            i1 += 1
            if board[i1][j1] == 'X':
                break
            if board[i1][j1] == 'o':
                return False
        i1, j1 = i, j
        while j1 - 1 >= 0:
            j1 -= 1
            if board[i1][j1] == 'X':
                break
            if board[i1][j1] == 'o':
                return False
        i1, j1 = i, j
        while j1 + 1 < N:
            j1 += 1
            if board[i1][j1] == 'X':
                break
            if board[i1][j1] == 'o':
                return False
        return True

    def tryPos(step):
        if step == len(pos):
            count = 0
            for x in range(N):
                for y in range(N):
                    if board[x][y] == 'o':
                        count += 1
            maxCount[0] = max(maxCount[0], count)
            return

        i, j = pos[step]
        if valid(i, j):
            board[i][j] = 'o'
            tryPos(step + 1)
            board[i][j] = '.'
        tryPos(step + 1)

    pos = []
    for y in range(N):
        for x in range(N):
            if board[y][x] == '.':
                pos.append([y, x])
    tryPos(0)
    return maxCount[0]


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
                board.append(list(self.fIn.readline().strip()))
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
            self.fOut.write("%s\n" % self.results[test])
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
