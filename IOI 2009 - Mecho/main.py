'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from collections import deque
parallelSolve = False
INF = 1 << 31


def solve(par):
    def valid(t):
        queue = deque()
        queue.append((mI, mJ))
        dist = {}
        dist[(mI, mJ)] = 0
        while queue:
            i, j = queue.popleft()
            direction = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
            for i1, j1 in direction:
                if i1 in range(N) and j1 in range(N)\
                        and (i1, j1) not in dist\
                        and board[i1][j1] != 'T'\
                        and board[i1][j1] > dist[(i, j)] // S + t:
                    queue.append((i1, j1))
                    dist[(i1, j1)] = dist[(i, j)] + 1
        return (dI, dJ) in dist

    N, S, board = par
    for i in range(N):
        for j in range(N):
            if board[i][j] == 'M':
                mI, mJ = i, j
                board[i][j] = 'G'
            elif board[i][j] == 'D':
                dI, dJ = i, j
                board[i][j] = 'G'
            elif board[i][j] in ['H']:
                board[i][j] = 0
            elif board[i][j] in ['T', 'D']:
                board[i][j] = 'T'
    for t in range(N * 2):
        for i in range(N):
            for j in range(N):
                direction = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
                for t in direction:
                    if t[0] in range(N) and t[1] in range(N) and board[i][j] != 'T'\
                            and board[i][j] != 'G' and board[t[0]][t[1]] != 'T'\
                            and (board[t[0]][t[1]] == 'G' or board[t[0]][t[1]] + 1 < board[i][j]):
                        board[t[0]][t[1]] = board[i][j] + 1

    if not valid(0):
        return -1
    low, high = 0, N * 2
    while low < high - 1:
        mid = (low + high) >> 1
        if valid(mid):  # low is always valid
            low = mid
        else:
            high = mid
    return low


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, S = map(int, self.fIn.readline().split())
            if N == 0:
                break
            self.numOfTests += 1
            board = []
            for i in range(N):
                board.append(list(self.fIn.readline().strip()))
            self.input.append((N, S, board))

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
