'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, perms = par
    original = list(range(1, N + 1))
    results = []
    for row in perms:
        flag = True
        incoming = list(original)
        incoming.reverse()
        curr = []
        for e in row:
            if not flag:
                break
            if curr and curr[-1] == e:
                curr.pop()
                continue
            while True:
                try:
                    curr.append(incoming.pop())
                except:
                    flag = False
                    break
                if curr[-1] == e:
                    curr.pop()
                    break
        if flag:
            results.append('Yes')
        else:
            results.append('No')
    return '\n' + '\n'.join(results)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            perms = []
            while True:
                row = map(int, self.fIn.readline().split())
                if row[0] == 0:
                    break
                perms.append(list(row))
            self.input.append((N, perms))

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
