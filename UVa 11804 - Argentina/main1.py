'''
Created on Jul 13, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from itertools import combinations
parallelSolve = False
INF = 1 << 31


class Player(object):

    """docstring for Player"""

    def __init__(self, data):
        self.a = data[1]
        self.d = data[2]
        self.n = data[0]

    def __lt__(self, other):
        return self.a > other.a or (self.a == other.a and self.d < other.d) or\
            (self.a == other.a and self.d == other.d and self.n < other.n)


def solve(par):
    players = par
    players = [Player(p) for p in players]
    players.sort()
    forwardNames = [p.n for p in players[:5]]
    backwardNames = [p.n for p in players[5:]]
    forwardNames.sort()
    backwardNames.sort()
    forward = ', '.join(forwardNames)
    backward = ', '.join(backwardNames)
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
