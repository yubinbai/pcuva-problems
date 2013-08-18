'''
Created on Jul 27, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
import collections
from numpypy import *
from multiprocessing.pool import Pool
from collections import deque
parallelSolve = False
INF = 1 << 31


def connected(w1, w2):
    N = len(w1)
    if N != len(w2):
        return False
    counter = 0
    for i in range(N):
        if w1[i] != w2[i]:
            counter += 1
    if counter == 1:
        return True
    else:
        return False


def solve(par):
    words, query = par
    N = len(words)
    wordDict = {}
    for i, w in enumerate(words):
        wordDict[w] = i
    graph = zeros((N, N), dtype=byte)
    for i in range(N):
        for j in range(i + 1, N):
            if connected(words[i], words[j]):
                graph[i, j] = graph[j, i] = 1
    results = []
    for q in query:
        # bfs
        queue = deque()
        queue.append(wordDict[q[0]])
        dist = [INF] * N
        dist[wordDict[q[0]]] = 0
        while queue:
            v1 = queue.popleft()
            for v2 in range(N):
                if v1 != v2 and graph[v1, v2] and dist[v2] == INF:
                    dist[v2] = dist[v1] + 1
                    queue.append(v2)
        results.append('%s %s %d' % (q[0], q[1], dist[wordDict[q[1]]]))
    return '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            words = []
            while True:
                line = self.fIn.readline().strip()
                if line == '*':
                    break
                words.append(line)
            query = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                query.append(line.split())

            self.input.append((words, query))

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
