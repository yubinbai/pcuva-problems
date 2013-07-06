'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
import collections
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    def bfs(start):
        for v in graph:
            dist[v] = INF
            for v2 in graph[v]:
                dist[v2] = INF
        dist[start] = 0
        q = collections.deque()
        q.append(start)
        while q:
            curr = q.popleft()
            for v in graph[curr]:
                if dist[v] == INF:
                    dist[v] = dist[curr] + 1
                    q.append(v)

    NC, graph, dest = par
    dist = {}
    result = []
    for d in dest:
        bfs(d[0])
        counter = sum([dist[v] > d[1] for v in dist])
        result.append('%d nodes not reachable from node %d with TTL = %d.' %
                      (counter, d[0], d[1]))
    return '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            NC = int(self.fIn.readline())
            if NC == 0:
                break
            self.numOfTests += 1
            graph = collections.defaultdict(list)
            row = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                row += map(int, line.split())
            for i in range(NC):
                graph[row[0]].append(row[1])
                graph[row[1]].append(row[0])
                del row[:2]
            dest = []
            while row[0] != 0:
                dest.append([row[0], row[1]])
                del row[:2]

            self.input.append((NC, graph, dest))

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
