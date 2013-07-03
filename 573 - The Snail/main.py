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
    H, U, D, F = par
    day = 0
    U2 = U
    H2 = 0
    while True:
        U2 = U * (1 - 0.01 * F * day)        
        H2 += U2
        if H2 > H:
            return 'success on day %d' % (day + 1)    
        H2 -= D
        if H2 < 0:
            return 'failure on day %d' % (day + 1)
        day += 1
        
        
class Solver:
    def getInput(self):
        self.input = []
        self.numOfTests = 0
        while True:
            H, U, D, F = map(int, self.fIn.readline().strip().split())
            if H == 0:
                break
            self.numOfTests += 1
            self.input.append((H, U, D, F)) 
            
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
        
