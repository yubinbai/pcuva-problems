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

    def __init__(self, name):
        self.name = self.pts = self.games = self.wins = self.ties =\
            self.losses = self.gdiff = self.goals = self.gagainst = 0
        self.name = name

    def calcMatch(self, match):
        '''Brazil#1@2#Norway'''
        s1, s2 = match.split('@')
        t1, g1 = s1.split('#')
        g2, t2 = s2.split('#')
        g1 = int(g1)
        g2 = int(g2)

        if t1 != self.name and t2 != self.name:
            return
        self.games += 1
        if t2 == self.name:
            t1, t2 = t2, t1
            g1, g2 = g2, g1
        if g1 > g2:
            self.pts += 3
            self.wins += 1
        elif g1 == g2:
            self.pts += 1
            self.ties += 1
        else:
            self.losses += 1
        self.gdiff += g1 - g2
        self.goals += g1
        self.gagainst += g2

    def __lt__(self, other):
        '''
        Most points earned.
        Most wins.
        Most goal difference (i.e. goals scored - goals against)
        Most goals scored.
        Less games played.
        Lexicographic order.
        '''
        if self.pts != other.pts:
            return self.pts > other.pts
        if self.wins != other.wins:
            return self.wins > other.wins
        if self.gdiff != other.gdiff:
            return self.gdiff > other.gdiff
        if self.goals != other.goals:
            return self.goals > other.goals
        if self.games != other.games:
            return self.games < other.games
        return self.name < other.name

    def __str__(self):
        '''
        [a]) Team_name [b]p, [c]g ([d]-[e]-[f]), [g]gd ([h]-[i])
        Where:
        [a] = team rank
        [b] = total points earned
        [c] = games played
        [d] = wins
        [e] = ties
        [f] = losses
        [g] = goal difference
        [h] = goals scored
        [i] = goals against
        '''
        return '%s %dp, %dg (%d-%d-%d), %dgd, (%d-%d)' %\
            (self.name, self.pts, self.games, self.wins, self.ties,
             self.losses, self.gdiff, self.goals, self.gagainst)


def solve(par):
    tname, N, K, teams, matches = par
    ts = [Team(t) for t in teams]
    for m in matches:
        for t in ts:
            t.calcMatch(m)
    ts.sort()
    result = []
    for i, t in enumerate(ts):
        result.append(str(i + 1) + ') ' + str(t))
    return tname + '\n' + '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            tname = self.fIn.readline().strip()
            N = int(self.fIn.readline())
            teams = []
            for i in range(N):
                teams.append(self.fIn.readline().strip())
            K = int(self.fIn.readline())
            matches = []
            for i in range(K):
                matches.append(self.fIn.readline().strip())

            self.input.append((tname, N, K, teams, matches))

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
