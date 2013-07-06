'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from collections import defaultdict
from itertools import combinations
parallelSolve = False
INF = 1 << 31


def solve(par):
    projects = par
    purge = set()
    N = len(projects)
    for p1,p2 in combinations(projects, 2):
        if p1 != p2:
            intersection = projects[p1] & projects[p2]
            projects[p1] -= intersection
            projects[p2] -= intersection

    results = []
    for p in projects:
        results.append([-1 * len(projects[p]), p])
    results.sort()

    s = []
    for row in results:
        if row[0] != 0:
            s.append('%s %d' % (row[1], -1 * row[0]))
    return '\n'.join(s)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        currProject = ''
        projects = defaultdict(set)
        while True:
            line = self.fIn.readline().strip()
            if line[0] == '1':
                self.numOfTests += 1
                self.input.append((projects))
                projects = defaultdict(set)
                continue
            if line[0] == '0':
                break
            if ord(line[0]) in range(ord('A'), ord('Z') + 1):
                currProject = line
            if ord(line[0]) in range(ord('a'), ord('z') + 1):
                projects[currProject].add(line)

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
