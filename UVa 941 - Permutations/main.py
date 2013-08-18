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
    factorial = [1, 1]
    for k in range(2, 21):
        factorial.append(k * factorial[-1])
    
    def PermN (seq, index):
        "Returns the i- th permutation of seq (in proper order)"
        seqc = list(seq[:])
        result = []
        fact = factorial[len(seq)]
        index %= fact
        while seqc:
            fact = fact / len(seqc)
            choice, index = index // fact, index % fact
            result += [seqc.pop(choice)]
        return result
              
    return ''.join(PermN(word, index))

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
        
