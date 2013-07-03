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
    def code(c):
        curr = 0
        if c in list('AEIOUYWH'):
            curr = '0'
        elif c in list('BPFV'):
            curr = '1'
        elif c in list('CSKGJQXZ'):
            curr = '2'
        elif c in list('DT'):
            curr = '3'
        elif c == 'L':
            curr = '4'
        elif c in list('MN'):
            curr = '5'
        elif c == 'R':
            curr = '6'
        return curr
    
    word = par
    result = []
    for i, c in enumerate(word):
        if i == 0:
            result.append(c)
            continue
        
        if code(word[i - 1]) == code(c):
            continue
        if code(c) != '0':
            result.append(code(c))
    
    result += ['0'] * 3
    return ''.join(result[:4])
            
class Solver:
    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn.read().split('\n'):
            if line != '':
                self.numOfTests += 1
                word = line
                self.input.append(word)
            else:
                break 
                
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
        
