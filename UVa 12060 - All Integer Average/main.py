'''
Created on 2013-6-6

@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False


def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


def solve(par):
    N, array = par
    S = sum(array)
    a = S // N
    b = S % N
    negFrac = False
    if a < 0 and b != 0:
        a += 1
        b = N - b
        negFrac = True
    g = gcd(abs(b), abs(N))
    b /= g
    N /= g
    if a == 0:
        if negFrac:
            result = [' ', '-', ' ']
            result1 = [str(b), '-' * len(str(N)), str(N)]
            for i in range(3):
                result[i] += result1[i]
            return '\n' + '\n'.join(result)
        else:
            return '\n' + '\n'.join([str(b), '-' * len(str(N)), str(N)])
    else:
        if b == 0:
            return '\n' + str(a)
        else:
            result = [' ' * len(str(a)), str(a), ' ' * len(str(a))]
            result1 = [str(b), '-' * len(str(N)), str(N)]
            for i in range(3):
                result[i] += result1[i]
            return '\n' + '\n'.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            row = line.strip().split()
            if len(row) == 1:
                break
            self.numOfTests += 1
            N = int(row[0])
            self.input.append((N, map(int, row[1:])))

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
            self.fOut.write("Case#%d: %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
