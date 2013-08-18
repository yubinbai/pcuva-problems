'''
Created on Jul 6, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):

    def floodfill(i, color):
        visited[i] = color
        for j in range(len(chars)):
            if i != j and not visited[j] and \
                    ((chars[i] + chars[j]) in edges or (chars[j] + chars[i]) in edges):
                floodfill(j, color)

    last, edges = par
    chars = [chr(e) for e in range(ord('A'), ord(last) + 1)]

    visited = [0] * len(chars)
    color = 0
    for i in range(len(chars)):
        if not visited[i]:
            color += 1
            floodfill(i, color)
    return color


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        self.fIn.readline()
        for i in range(self.numOfTests):
            last = self.fIn.readline().strip()
            edges = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                edges.append(line)
            self.input.append((last, edges))

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
