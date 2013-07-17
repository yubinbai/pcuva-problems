'''
Created on Jul 13, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from itertools import combinations
parallelSolve = False
INF = 1 << 31


def solve(par):
    players = par
    players.sort()
    currAtt, currDef,  currC = -1, -1, None
    totalDef = sum(p[2] for p in players)
    for c in combinations(players, 5):
        att = sum(p[1] for p in c)
        defend = totalDef - sum(p[2] for p in c)
        if att > currAtt or (att == currAtt and defend > currDef):
            currAtt, currDef, currC = att, defend, tuple(c)
    forward = ', '.join([p[0] for p in currC])
    backward = ', '.join([p[0] for p in players if p not in currC])
    return '(%s)' % forward + '\n' + '(%s)' % backward


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for iterTest in range(self.numOfTests):
            players = []
            for i in range(10):
                row = self.fIn.readline().strip().split()
                row[1] = int(row[1])
                row[2] = int(row[2])
                players.append(tuple(row))

            self.input.append((players))

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
