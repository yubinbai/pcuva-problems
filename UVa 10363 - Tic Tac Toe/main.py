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
    def checkwin():
        if countO == 3:
            win[0] = True
        if countX == 3:
            win[1] = True

    board = par
    totalO = totalX = 0  # first one is O, second is X
    win = [False, False]

    for i in range(3):
        countO = countX = 0
        for j in range(3):
            if board[i][j] == 'O':
                countO += 1
            elif board[i][j] == 'X':
                countX += 1
        totalO += countO
        totalX += countX
        checkwin()

    for j in range(3):
        countO = countX = 0
        for i in range(3):
            if board[i][j] == 'O':
                countO += 1
            elif board[i][j] == 'X':
                countX += 1
        checkwin()

    countO = countX = 0
    for i in range(3):
        if board[i][i] == 'O':
            countO += 1
        elif board[i][i] == 'X':
            countX += 1
        checkwin()

    countO = countX = 0
    for i in range(3):
        if board[i][2 - i] == 'O':
            countO += 1
        elif board[i][2 - i] == 'X':
            countX += 1
        checkwin()

    if totalO > totalX or totalX > totalO + 1:
        return False
    if win[0] and win[1]:
        return False
    if win[0] and totalO < totalX:
        return False
    if win[1] and totalX <= totalO:
        return False
    return True


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for i in range(self.numOfTests):
            board = []
            for j in range(3):
                board.append(self.fIn.readline().strip())
            self.input.append(list(board))

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
            self.fOut.write("Case #%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
