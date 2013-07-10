'''
Created on Jul 9, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from collections import Counter
from SegmentTreeSum import SegmentTreeSum
from bitstring import BitArray
parallelSolve = False
INF = 1 << 31
ZERO = 100000


def solve(par):
    M, Q, construct, queries = par
    bits = BitArray()
    for m in construct:
        for i in range(m[0]):
            bits.append('0b' + m[1])

    nodes = set()
    for q in queries:  # (i-1, i]
        nodes.add(q[1] - 1)
        nodes.add(q[2])
    nodes = list(nodes)
    nodes.sort()

    count = [0] * len(nodes)
    for i in range(1, len(nodes)):
        count[i] = bits[nodes[i - 1] + 1:nodes[i] + 1].count(1)
    size = [0] * len(nodes)
    for i in range(1, len(nodes)):
        size[i] = nodes[i] - nodes[i - 1]

    tree = SegmentTreeSum(len(nodes))
    tree.buildTree(count, 1, 0, len(nodes) - 1)

    results = []
    for q in queries:
        i1 = nodes.index(q[1] - 1)
        i2 = nodes.index(q[2])
        if q[0] == 'F':
            for i in range(i1 + 1, i2 + 1):
                count[i] = size[i]
                tree.update(i, size[i])
        if q[0] == 'E':
            for i in range(i1 + 1, i2 + 1):
                count[i] = 0
                tree.update(i, 0)
        if q[0] == 'I':
            for i in range(i1 + 1, i2 + 1):
                count[i] = size[i] - count[i]
                tree.update(i, count[i])
        if q[0] == 'S':
            results.append(tree.query(i1 + 1, i2))
    return '\n'.join(str(e) for e in results) + '\n'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for t in range(self.numOfTests):
            M = int(self.fIn.readline())
            construct = []
            for j in range(M):
                v1 = int(self.fIn.readline())
                v2 = self.fIn.readline().strip()
                construct.append([v1, v2])
            Q = int(self.fIn.readline())
            queries = []
            for i in range(Q):
                row = self.fIn.readline().split()
                row[1] = int(row[1])
                row[2] = int(row[2])
                queries.append(row)
            self.input.append((M, Q, construct, queries))

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
