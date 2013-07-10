'''
Created on Jul 9, 2013

@author: Yubin Bai

Segment Tree Library
The segment tree is stored like a heap array
'''
import time
from multiprocessing.pool import Pool
from SegmentTreeMax import SegmentTreeMax
from collections import Counter
from bisect import *
parallelSolve = False
INF = 1 << 31
ZERO = 100000


def solve(par):
    N, Q, array, queries = par

    freq = Counter(array)
    keys = freq.keys()
    keys.sort()
    values = [freq[k] for k in keys]
    tree = SegmentTreeMax(len(values))
    tree.buildTree(values)

    result = []
    for q in queries:
        p1 = bisect_left(array, array[q[0]])
        p2 = bisect_left(array, array[q[1]])
        m = 0
        if p1 == p2:
            m = q[1] - q[0] + 1
            result.append(m)
        else:
            p3 = bisect_right(array, array[q[0]])
            m1 = p3 - q[0]
            m2 = q[1] - p2 + 1
            m = max(m1, m2)
            i1 = keys.index(array[p3])
            i2 = keys.index(array[p2]) - 1
            mq = tree.query(values, i1, i2)
            if mq == -1:
                mq = 0
            else:
                mq = values[mq]
            result.append(max(m, mq))

    return '\n'.join(str(e) for e in result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N, Q = map(int, self.fIn.readline().split())
            if N == 0:
                break
            self.numOfTests += 1
            array = [-1 * INF]
            array.extend(map(int, self.fIn.readline().split()))
            queries = []
            for i in range(Q):
                queries.append(map(int, self.fIn.readline().split()))
            self.input.append((N, Q, array, queries))

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
