'''
Created on Jul 12, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from bisect import *
parallelSolve = False
INF = 1 << 31


class SegmentTreeMin:

    def __init__(self, N):
        self.counter = [0] * N
        self.length = 1
        while self.length < 2 * N:
            self.length <<= 1
        self.tree = [0] * self.length

    def buildTree(self, A, node, b, e):
        if b == e:
            self.tree[node] = b
        else:
            left = 2 * node
            right = 2 * node + 1
            self.buildTree(A, left, b, (b + e) // 2)
            self.buildTree(A, right, (b + e) // 2 + 1, e)
            lContent = self.tree[left]
            rContent = self.tree[right]
            if A[lContent] <= A[rContent]:
                self.tree[node] = lContent
            else:
                self.tree[node] = rContent

    def query(self, A, i, j):
        return self._query(A, 1, 0, len(A) - 1, i, j)

    def _query(self, A, node, b, e, i, j):
        '''
        find min in interval [i, j]
        '''
        if i > e or j < b:
            return -1
        if b >= i and e <= j:
            return self.tree[node]
        p1 = self._query(A, 2 * node, b, (b + e) // 2, i, j)
        p2 = self._query(A, 2 * node + 1, (b + e) // 2 + 1, e, i, j)
        if p1 == -1:
            return p2
        if p2 == -1:
            return p1
        if A[p1] <= A[p2]:
            return p1
        else:
            return p2

    def update(self, A, pos, value):
        '''
        update A[pos] to a new value
        value need to be smaller than old one
        '''
        if A[pos] < value:
            raise KeyError
        A[pos] = value

        def _update(node, p, b, e):
            if p < b or p > e:
                return
            if b == e:
                self.tree[node] = p
                return
            if A[p] < A[self.tree[node]]:
                self.tree[node] = p
            _update(node * 2, p, b, (b + e) // 2)
            _update(node * 2 + 1, p, (b + e) // 2 + 1, e)
        _update(1, pos, 0, len(A) - 1)

    def updateRange(self, A, i, j, value):
        '''
        update the values in range [i, j] of A to be bigger or equal to value
        '''
        def _update(node, b, e):
            if i > e or j < b:
                return
            if b == e:
                if value > A[b]:
                    A[b] = value
                    self.counter[b] += 1
                return
            i1 = self._query(A, node, b, e, i, j)
            if A[i1] > value:
                return
            _update(node * 2, b, (b + e) // 2)
            _update(node * 2 + 1, (b + e) // 2 + 1, e)
            if A[self.tree[node * 2]] <= A[self.tree[node * 2 + 1]]:
                self.tree[node] = self.tree[node * 2]
            else:
                self.tree[node] = self.tree[node * 2 + 1]

        _update(1, 0, len(A) - 1)


def solve(par):
    N, array = par
    node = set()
    for a in array:
        node.add(a[0])
        node.add(a[1])
    node = list(node)
    node.sort()
    nodeLen = len(node)
    skyline = [0] * nodeLen
    tree = SegmentTreeMin(nodeLen)
    tree.buildTree(skyline, 1, 0, nodeLen - 1)

    for a in array:
        i1 = bisect_left(node, a[0])
        i2 = bisect_left(node, a[1]) - 1
        tree.updateRange(skyline, i1, i2, a[2])
        b = 100

    size = [0] * nodeLen
    for i in range(nodeLen - 1):
        size[i] = node[i + 1] - node[i]
    size[-1] = N - node[-1]

    overlap = sum(size[i] * tree.counter[i] for i in range(nodeLen))
    print overlap
    return overlap


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            N = int(self.fIn.readline())
            array = []
            for i in range(N):
                array.append(map(int, self.fIn.readline().split()))
            self.input.append((N, array))

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
