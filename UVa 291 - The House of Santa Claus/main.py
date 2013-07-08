'''
Created on Jul 5, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from heapq import *
parallelSolve = False
INF = 1 << 31


def solve(par):
    graph = {1: [2, 3, 5], 2: [1, 3, 5], 3:
             [1, 2, 4, 5], 4: [3, 5], 5: [1, 2, 3, 4]}
    edges = set()
    for v in graph:
        for v2 in graph[v]:
            if v < v2:
                edges.add((v, v2))
    path = [1]
    pathEdges = []
    results = []
    print(edges)

    def backtrack(step):
        if step == len(edges):
            results.append(''.join(str(e) for e in path))
        v1 = path[-1]
        for v2 in graph[v1]:
            if v1 < v2 and (v1, v2) not in pathEdges:
                path.append(v2)
                pathEdges.append((v1, v2))
                backtrack(step + 1)
                path.pop()
                pathEdges.pop()
            if v1 > v2 and (v2, v1) not in pathEdges:
                path.append(v2)
                pathEdges.append((v2, v1))
                backtrack(step + 1)
                path.pop()
                pathEdges.pop()

    backtrack(0)
    results.sort()
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = 1
        self.input = []
        self.input.append([])

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
