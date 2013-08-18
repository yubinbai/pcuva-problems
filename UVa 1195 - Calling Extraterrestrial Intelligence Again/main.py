'''
Created on Jul 17, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bitstring import BitArray
from bisect import bisect_left
from math import sqrt
parallelSolve = False
INF = 1 << 31


def prime_sieve(top=10000000):
    b = BitArray(top)  # bitstring of ’0’ bits
    for i in range(2, top):
        if not b[i]:
            yield i
            # i is prime, so set all its multiples to ’1’.
        b.set(True, range(i * i, top, i))


def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i - 1]
    raise ValueError


def solve(par):
    M, A, B = par
    a = sqrt(M)
    a = find_lt(primes, a)
    maxA, maxB, maxM = a, a, a ** 2
    b = a
    while a * 1.0 / b >= A * 1.0 / B:
        if a * b > maxM:
            maxA, maxB, maxM = a, b, a * b
        try:
            a = find_lt(primes, a)
        except:
            break
        try:
            b = find_lt(primes, M * 1.0 / a)
        except:
            break
    return '%d %d' % (maxA, maxB)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            M, A, B = map(int, line.split())
            if M == 0:
                break
            self.numOfTests += 1
            self.input.append((M, A, B))

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
    primes = list(prime_sieve(100000))
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
