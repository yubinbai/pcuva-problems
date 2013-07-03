'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
infinity = 1 << 30

class Proposal:
    def __init__(self, p):
        self.name = p[0]
        self.price = p[1]
        self.req = int(p[2])
    def __lt__(self, other):
        if self.req != other.req:
            return self.req > other.req
        else:
            return self.price < other.price

def solve(par):
    N, P, proposals = par
    pros = []
    for p in proposals:
        pros.append(Proposal(p))
    pros.sort()
    return pros[0].name
        
class Solver:
    def getInput(self):
        self.numOfTests = 0
        self.input = []
        
        while True:
            N, P = map(int, self.fIn.readline().strip().split())
            if N == 0:
                break
            self.numOfTests += 1
            for i in range(N):
                self.fIn.readline()
            proposals = []
            for i in range(P):
                p = []
                p.append(self.fIn.readline().strip())
                p.extend(map(float, self.fIn.readline().strip().split()))
                for j in range(int(p[2])):
                    self.fIn.readline()
                proposals.append(p)
            self.input.append((N, P, proposals)) 
            
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
        
