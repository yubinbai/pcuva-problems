'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
infinity = 1 << 30

def solve(par):
    queries = par
    d = 0.0
    s = 0.0
    t = '00:00:00'
    results = []
    for q in queries:
        if len(q) == 2:
            h1, m1, s1 = map(int, q[0].split(':'))
            h2, m2, s2 = map(int, t.split(':'))
            d += (h1 - h2) * s + (m1 - m2) * s / 60.0 + (s1 - s2) * s / 3600.0
            s = float(q[1])
            t = q[0]
        else:
            h1, m1, s1 = map(int, q[0].split(':'))
            h2, m2, s2 = map(int, t.split(':'))
            d += (h1 - h2) * s + (m1 - m2) * s / 60.0 + (s1 - s2) * s / 3600.0
            t = q[0]
            results.append(' '.join([q[0], '%.2f' % d, 'km']))
    return '\n'.join(results)
    
        
class Solver:
    def getInput(self):
        self.numOfTests = 1
        self.input = []
        queries = []
        while True:
            line = self.fIn.readline()
            if line == '':
                break
            row = line.strip().split()
            queries.append(list(row))
            
        self.input.append((queries)) 
            
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
        
