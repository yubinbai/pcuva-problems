'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, M, c1, c2, c3 = par
    checkPos = [c1, c2, c3]
    checkStep = [N * M // 4, N * M // 2, N * M * 3 // 4]
    path = set()
    pathCount = [0]

    def valid(step, t):
        if t[0] not in range(N) or t[1] not in range(M):
            return False
        for i in range(3):
            if step == checkStep[i] and t != checkPos[i]:
                return False
            if t == checkPos[i] and step != checkStep[i]:
                return False
        if step in range(1, checkStep[0]):
            dist = abs(t[0] - checkPos[0][0]) + abs(t[1] - checkPos[0][1])
            if dist > checkStep[0] - step:
                return False
        if step in range(checkStep[0] + 1, checkStep[1]):
            dist = abs(t[0] - checkPos[1][0]) + abs(t[1] - checkPos[1][1])
            if dist > checkStep[1] - step:
                return False
        if step in range(checkStep[1] + 1, checkStep[2]):
            dist = abs(t[0] - checkPos[2][0]) + abs(t[1] - checkPos[2][1])
            if dist > checkStep[2] - step:
                return False
        if step in range(checkStep[2] + 1, N * M):
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
            if t in path:
                continue
            if valid(step + 1, t):
                path.add(t)
                backtrack(step + 1, t[0], t[1])
                path.remove(t)

    path.add((0, 0))
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
