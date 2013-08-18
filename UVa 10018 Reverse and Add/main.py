'''
Created on Jul 28, 2013
@author: Yubin Bai
All rights reserved.
'''
import time
from numpypy import *
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def isPalindrome(number):
    N = 1
    while 10 ** N < number:
        N += 1

    while N > 1:
        d1 = number // (10 ** (N - 1))
        d2 = number % 10
        if d1 != d2:
            return False
        number %= (10 ** (N - 1))
        number //= 10
        N -= 2
    return True


def reverseAdd(number):
    original = number
    reverse = 0
    while number:
        reverse *= 10
        reverse += number % 10
        number //= 10
    return original + reverse


def solve(par):
    number = par
    for counter in range(20):
        if isPalindrome(number):
            return '%d %d' % (counter, number)
        number = reverseAdd(number)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):

            self.input.append((int(self.fIn.readline())))

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
            self.fOut.write("%d %s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()
if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
