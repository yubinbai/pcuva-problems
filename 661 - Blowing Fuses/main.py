'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
from itertools import compress
parallelSolve = False
INF = 1 << 32

def solve(par):
    n, m, c, amp, ops = par
    status = [0] * n
    currMax = 0
    for o in ops:
        status[o - 1] += 1
        s = sum(compress(amp, status))
        if s > c:
            return 'Blown'
        currMax = max(currMax, s)
        status[o - 1] %= 2
    return 'Secure, max is %d' % currMax
    
        
class Solver:
    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            n, m, c = map(int, self.fIn.readline().strip().split())
            if n == 0:
                break
            self.numOfTests += 1
            amp = []
            for i in range(n):
                amp.append(int(self.fIn.readline()))
            ops = []
            for i in range(m):
                ops.append(int(self.fIn.readline()))
            self.input.append((n, m, c, amp, ops))
            
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
        
