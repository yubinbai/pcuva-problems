'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from EdmondsKarp import edmondsKarp
from math import ceil
parallelSolve = False
INF = 1 << 31


def solve(par):
    def win(i, j, years):
        return human[i * 2] + (years - dist[i][j]) * human[i * 2 + 1]\
            >= (alien[j * 2] + years * alien[j * 2 + 1])

    def valid(years):
        size = H + A + 2
        source = size - 2
        target = size - 1
        graph = []
        for i in range(size):
            row = {}
            for j in range(size):
                row[j] = 0
            graph.append(row)
        for i in range(H):
            graph[source][i] = 1
        for i in range(H, size - 2):
            graph[i][target] = 1
        for i in range(H):
            for j in range(A):
                if win(i, j, years):
                    graph[i][j + H] = 1
        max_flow = edmondsKarp(graph, source, target)
        return max_flow >= A

    H, A, human, alien, dist = par
    graph = []
    low = 0
    high = 10000
    epi = 1E-2
    if H < A or not valid(high):
        return 'IMPOSSIBLE'
    while low < high - epi:
        mid = (low + high) / 2.0
        if valid(mid):
            high = mid
        else:
            low = mid
    return int(high)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            H, A = map(int, self.fIn.readline().split())
            if H == 0:
                break
            self.numOfTests += 1
            human = map(int, self.fIn.readline().split())
            alien = map(int, self.fIn.readline().split())
            dist = []
            for i in range(H):
                dist.append(map(int, self.fIn.readline().split()))
            self.input.append((H, A, human, alien, dist))

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
