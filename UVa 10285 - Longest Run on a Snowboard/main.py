'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


def solve(par):
    name, N, M, area = par
    memo = []
    nextPos = []
    for i in range(N):
        memo.append([0] * M)
        nextPos.append([0] * M)  # 0,1,2,3,4 = None, UP, DOWN, LEFT, RIGHT

    def dp(i, j):
        if memo[i][j] != 0:
            return memo[i][j]
        directions = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
        currP, currMax = 0, 1
        for p, t in enumerate(directions):
            if t[0] in range(N) and t[1] in range(M) and \
                    area[i][j] > area[t[0]][t[1]] and gcd(area[i][j], area[t[0]][t[1]]) > 1:
                curr = dp(*t) + 1
                if curr > currMax:
                    currP, currMax = p + 1, curr

        memo[i][j] = currMax
        nextPos[i][j] = currP
        return memo[i][j]

    maxI, maxJ, currMax = -1, -1, -1
    for i in range(N):
        for j in range(M):
            if dp(i, j) > currMax:
                maxI, maxJ, currMax = i, j, dp(i, j)

    path = []
    i, j = maxI, maxJ
    while True:
        path.append(area[i][j])
        if nextPos[i][j] == 0:
            break
        if nextPos[i][j] == 1:
            i -= 1
        elif nextPos[i][j] == 2:
            i += 1
        elif nextPos[i][j] == 3:
            j -= 1
        elif nextPos[i][j] == 4:
            j += 1

    return '%s: %d\n%s' % (name, currMax, ' '.join(str(e) for e in path))


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for iterTest in range(self.numOfTests):
            name, N, M = self.fIn.readline().strip().split()
            N = int(N)
            M = int(M)
            area = []
            for i in range(N):
                area.append(map(int, self.fIn.readline().split()))
            self.input.append((name, N, M, area))

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
9
