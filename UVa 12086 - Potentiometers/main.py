'''
Created on Jul 11, 2013

@author: Yubin Bai

Segment Tree Library
The segment tree is stored like a heap array
'''
import time
from multiprocessing.pool import Pool
from SegmentTreeSum import SegmentTreeSum
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, array, queries = par
    tree = SegmentTreeSum(N)
    tree.buildTree(array)
    result = ['']
    for q in queries:
        if q[0] == 'S':
            x = int(q[1]) - 1
            v = int(q[2])
            tree.update(x, v)
        if q[0] == 'M':
            x = int(q[1]) - 1
            y = int(q[2]) - 1
            result.append(tree.query(x, y))
    return '\n'.join(str(e) for e in result)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            array = []
            for i in range(N):
                array.append(int(self.fIn.readline()))
            queries = []
            while True:
                line = self.fIn.readline().split()
                if line[0] == 'END':
                    break
                queries.append(line)

            self.input.append((N, array, queries))

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
            self.fOut.write("Case %d:%s\n" % (test + 1, self.results[test]))
        self.fIn.close()
        self.fOut.close()

if __name__ == '__main__':
    solver = Solver()
    if parallelSolve:
        solver.parallel()
    else:
        solver.sequential()
