'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from numpypy import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, M, c1, c2, c3 = par
    checkPos = [c1, c2, c3]
    checkStep = [N * M // 4, N * M // 2, N * M * 3 // 4]
    path = zeros((N + 1, M + 1), dtype=byte)
    pathCount = [0]

    def valid(step, t):
        if t[0] not in range(N) or t[1] not in range(M):
            return False
        for i in range(3):
            if step == checkStep[i] and t != checkPos[i]:
                return False
            if t == checkPos[i] and step != checkStep[i]:
                return False
        if step >= 1 and step < checkStep[0]:
            dist = abs(t[0] - checkPos[0][0]) + abs(t[1] - checkPos[0][1])
            if dist > checkStep[0] - step:
                return False
        if step in range(checkStep[0] + 1, checkStep[1]):
            dist = abs(t[0] - checkPos[1][0]) + abs(t[1] - checkPos[1][1])
            if dist > checkStep[1] - step:
                return False
        if step >= checkStep[1] + 1 and step < checkStep[2]:
            dist = abs(t[0] - checkPos[2][0]) + abs(t[1] - checkPos[2][1])
            if dist > checkStep[2] - step:
                return False
        if step >= checkStep[2] + 1 and step < N * M:
            dist = abs(t[0] - 0) + abs(t[1] - 1)
            if dist > N * M - step:
                return False
        return True

    def backtrack(step, i, j):
        if step == N * M:
            if (i, j) == (0, 1):
                pathCount[0] += 1
            return
        directions = [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]
        for t in directions:
            i1, j1 = t
            if path[i1, j1]:
                continue
            if valid(step + 1, t):
                path[i1, j1] = 1
                backtrack(step + 1, i1, j1)
                path[i1, j1] = 0

    path[0, 0] = 1
    backtrack(1, 0, 0)
    return pathCount[0]


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, M = map(int, self.fIn.readline().strip().split())
            if N == 0:
                break
            self.numOfTests += 1
            row = map(int, self.fIn.readline().split())
            c1 = tuple(row[:2])
            c2 = tuple(row[2:4])
            c3 = tuple(row[-2:])
            self.input.append((N, M, c1, c2, c3))

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
