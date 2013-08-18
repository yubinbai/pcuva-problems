'''
Created on Jul 6, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from numpypy import *
parallelSolve = False
INF = 1 << 31


def solve(par):

    def floodfill(i, j, color):
        colorMat[i, j] = color
        neighbors = [(i - 1, j - 1), (i - 1, j), (i - 1, j + 1),
                     (i, j - 1), (i, j + 1), (i + 1, j - 1), (i + 1, j), (i + 1, j + 1)]
        for i1, j1 in neighbors:
            if i1 >= 0 and i1 < N and j1 >= 0 and j1 < M and \
                    not colorMat[i1, j1] and mat[i1][j1] == 'W':
                floodfill(i1, j1, color)

    N, M, mat, query = par

    colorMat = zeros((N, M), dtype=int)
    color = 0
    for i in range(N):
        for j in range(M):
            if not colorMat[i, j] and mat[i][j] == 'W':
                color += 1
                floodfill(i, j, color)

    cCount = [0] * (color + 1)
    for i in range(N):
        for j in range(M):
            cCount[colorMat[i, j]] += 1
    result = []
    for q in query:
        result.append(str(cCount[colorMat[q[0] - 1, q[1] - 1]]))
    return '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        self.fIn.readline()
        for i in range(self.numOfTests):
            mat = []
            query = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                if line[0] in ['W', 'L']:
                    mat.append(line)
                else:
                    query.append(map(int, line.split()))
            N = len(mat)
            M = len(mat[0])
            self.input.append((N, M, mat, query))

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
