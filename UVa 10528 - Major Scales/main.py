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
    line = par
    notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    majors = []
    tones = [2, 2, 1, 2, 2, 2, 1]
    for n in notes:
        row = []
        p = notes.index(n)
        for t in tones:
            row.append(notes[p])
            p += t
            p %= len(notes)
        majors.append(row)

    results = []
    for m in majors:
        flag = True
        for n in line:
            if n not in m:
                flag = False
                break
        if flag:
            results.append(m[0])

    return ' '.join(results)

class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            if line == 'END':
                break
            self.numOfTests += 1
            self.input.append(line.split())

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
