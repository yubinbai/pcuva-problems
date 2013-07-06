'''
Created on Jul 3, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    '''
    We use a stack
    When an operand is read, output it
    When an operator is read
    Pop until the top of the stack has an element of lower precedence
    Then push it
    When ) is found, pop until we find the matching (
    ( has the lowest precedence when in the stack
    but has the highest precedence when in the input
    When we reach the end of input, pop until the stack is empty
    '''
    exp = par
    operators = []
    result = []
    for e in exp:
        if e[0] in list('1234567890'):
            result.append(e)
        elif e[0] in ['+', '-']:
            while operators and operators[-1] not in ['(']:
                result.append(operators.pop())
            operators.append(e[0])
        elif e[0] in ['*', '/']:
            while operators and operators[-1] not in ['+', '-', '(']:
                result.append(operators.pop())
            operators.append(e[0])
        elif e[0] == '(':
            operators.append(e[0])
        elif e[0] == ')':
            while operators and operators[-1] != '(':
                result.append(operators.pop())
            if operators and operators[-1] == '(':
                operators.pop()
    while operators:
        result.append(operators.pop())
    return ' '.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        self.fIn.readline()
        for i in range(self.numOfTests):
            line = self.fIn.readline()
            if line == '':
                break
            exp = []
            while True:
                line = self.fIn.readline().strip()
                if line == '':
                    break
                exp.append(line.strip())
            self.input.append((exp))

    def __init__(self):
        self.fIn = open('input.txt')
        self.fOut = open('output.txt', 'w')
        self.results = []

    def parallel(self):
        self.getInput()
        p = Pool(4)
        millis1 = int(round(time.time() * 1000))
        self.results = p.map(solve, self.input)
        milli2 = int(round(time.time() * 1000))
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
