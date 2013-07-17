'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from math import sqrt, ceil
from collections import deque
from EdmondsKarp import edmondsKarp
parallelSolve = False
INF = 1 << 31


def solve(par):
    def dist(p1, p2):
        return sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

    def valid(length):
        size = len(red) + len(blue) + 2
        source = size - 2
        target = size - 1
        graph = []
        for i in range(size):
            row = {}
            for j in range(size):
                row[j] = 0
            graph.append(row)
        for i in range(len(red)):
            graph[source][i] = 1
        for i in range(len(red), size - 2):
            graph[i][target] = 1
        for i, r in enumerate(red):
            for j, b in enumerate(blue):
                if dist(r, b) <= length:
                    graph[i][j + len(red)] = 1
        max_flow = edmondsKarp(graph, source, target)
        return max_flow >= K

    P, K, red, blue = par
    if len(red) < K or len(blue) < K:
        return 'Impossible'
    low = 1
    high = 2000 * 1.414
    epi = 1E-2
    while low < high - epi:
        mid = (low + high) / 2.0
        if valid(mid):
            high = mid
        else:
            low = mid
    return int(ceil(high))


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            self.fIn.readline()
            P, K = map(int, self.fIn.readline().split())
            red = []
            blue = []
            for i in range(P):
                row = self.fIn.readline().strip().split()
                if row[2] == 'red':
                    red.append(map(int, row[:2]))
                else:
                    blue.append(map(int, row[:2]))
            self.input.append((P, K, red, blue))

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
