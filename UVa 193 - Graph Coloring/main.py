'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):
    def dfs(step, currColor, currNode):
        '''
        dfs to get the results
        0 - unvisited, 1 - black, 2 -white
        '''
        color[currNode] = currColor
        c = Counter(color)
        if c[1] > maxBlack[0]:
            maxBlack[0] = c[1]
            maxBlack[1] = tuple(color)
        if step == N or (N - step) + c[1] < maxBlack[0]:
            return

        for i in range(N):
            if color[i] == 0 and (i, currNode) in edges:
                blackValid = True
                for j in range(N):
                    if (i, j) in edges and color[j] == 1:
                        blackValid = False
                        break
                if blackValid:
                    dfs(step + 1, 1, i)
                dfs(step + 1, 2, i)
        color[currNode] = 0

    N, K, edges = par
    color = [0] * N
    maxBlack = [0, 0]
    dfs(0, 1, 0)
    dfs(0, 2, 0)
    return '%d\n%s' %\
        (maxBlack[0], ' '.join(str(i + 1)
                               for i in range(N) if maxBlack[1][i] == 1))


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for iterTest in range(self.numOfTests):
            N, K = map(int, self.fIn.readline().split())
            edges = set()
            for i in range(K):
                row = self.fIn.readline().strip().split()
                row[0] = int(row[0]) - 1
                row[1] = int(row[1]) - 1
                edges.add(tuple(row))
                edges.add(tuple(reversed(row)))

            self.input.append((N, K, edges))

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
