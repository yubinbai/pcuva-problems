'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 30


def solve(par):
    '''
    find the i-th permutation of word
    '''
    word, index = par
    perm = {}
    n = len(word)
    fact = [1, 1]
    for k in range(2, 21):
        fact.append(k * fact[-1])

    # compute factorial code
    for k in range(n):
        perm[k] = index / fact[n - 1 - k]
        index %= fact[n - 1 - k]

    # readjust values to obtain the permutation
    # start from the end and check if preceding values are lower
    for k in range(n - 1, 0, -1):
        for j in range(k - 1, -1, -1):
            if (perm[j] <= perm[k]):
                perm[k] += 1
    word = list(word)
    word.sort()
    return ''.join(word[perm[k]] for k in range(n))


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for test in range(self.numOfTests):
            word = self.fIn.readline().strip()
            N = int(self.fIn.readline().strip())
            self.input.append((word, N))

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
            self.fOut.write("Case #%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
