'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 30


class Team(object):

    """docstring for Team"""

    def __init__(self, n):
        self.t = 0
        self.n = n
        self.solved = set()
        self.penalty = {}

    def __lt__(self, other):
        '''
        number of problems solved
        time penalty
        '''
        if len(self.solved) != len(other.solved):
            return len(self.solved) > len(other.solved)
        t1 = sum(self.penalty[e] for e in self.solved)
        t2 = sum(other.penalty[e] for e in other.solved)
        return t1 < t2

    def __str__(self):
        return '%d %d %d' % (self.n, len(self.solved),
                             sum(self.penalty[e] for e in self.solved))


def solve(par):
    subs = par
    teams = [Team(i) for i in range(101)]
    tSet = set()
    for s in subs:
        team, prob, time, res = int(s[0]), int(s[1]), int(s[2]), s[3]
        tSet.add(team)
        if res == 'C':
            teams[team].solved.add(prob)
            try:
                teams[team].penalty[prob] += time
            except:
                teams[team].penalty[prob] = time
        if res == 'I':
            try:
                teams[team].penalty[prob] += 20
            except:
                teams[team].penalty[prob] = 20
    teams.sort()
    return '\n'.join(str(t) for t in teams[:len(tSet)])


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            self.fIn.readline()
            subs = []
            while True:
                line = self.fIn.readline().split()
                if len(line) < 4:
                    break
                subs.append(list(line))
            self.input.append(subs)

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
