'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
import bisect
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):

    def invIndex(left, right):
        if left >= right:
            return 0
        mid = (left + right) // 2
        c1 = invIndex(left, mid)
        c2 = invIndex(mid + 1, right)
        c3 = merge(left, mid, right)
        return c1 + c2 + c3

    def merge(left, mid, right):
        '''
        merge left..mid and mid+1..right
        '''
        counter = 0
        for curr in range(mid + 1, right + 1):
            c1 = bisect.bisect_left(A, A[curr], left, mid + 1)
            counter += (mid + 1 - left) - (c1 - left)

        l1 = A[left: mid + 1]
        l2 = A[mid + 1:right + 1]
        l1.append(INF)
        l2.append(INF)
        i1 = i2 = 0

        for curr in range(left, right + 1):
            if l1[i1] <= l2[i2]:
                A[curr] = l1[i1]
                i1 += 1
            else:
                A[curr] = l2[i2]
                i2 += 1
        return counter

    N, A = par
    if invIndex(0, N - 1) % 2:
        return 'Marcelo'
    else:
        return 'Carlos'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            A = map(int, self.fIn.readline().split())
            if A[0] == 0:
                break
            self.numOfTests += 1
            self.input.append((A[0], A[1:]))

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
