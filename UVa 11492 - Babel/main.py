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
    M, O, D, graph = par
    vertices = set()
    for e in graph:
        vertices.add(e[0])
        vertices.add(e[1])
    vertices.add(O)
    vertices.add(D)

    def relax(u, v, w):
        '''
        node u, node v, weight w
        '''
        if dist[v][0] > dist[u][0] + len(w) and w[0] != dist[u][1]:
            dist[v] = (dist[u][0] + len(w)), w[0]

    # bellman-ford 
    dist = {}
    for v in vertices:
        dist[v] = INF, ' '
    dist[O] = 0, ' '
    for v in vertices:
        for e in graph:
            relax(e[0], e[1], e[2])
            relax(e[1], e[0], e[2])
    if dist[D][0] >= INF:
        return 'impossivel'
    else:
        return dist[D][0]


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            M = int(self.fIn.readline())
            if M == 0:
                break
            self.numOfTests += 1
            O, D = self.fIn.readline().split()
            graph = []
            for i in range(M):
                graph.append(self.fIn.readline().split())
            self.input.append((M, O, D, graph))

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
