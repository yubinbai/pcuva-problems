'''
Created on Jul 15, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
from collections import Counter
parallelSolve = False
INF = 1 << 31


def solve(par):
    N, K, array = par

    def valid(n1):
        currN = 0
        count = 0
        for i in range(N):
            if array[i] > currN:
                count += 1
                currN = n1
            currN -= array[i]
        return count <= K

    low = array[0]
    high = sum(array)
    while low < high:
        mid = (low + high) >> 1
        if valid(mid):
            high = mid
        else:
            low = mid + 1
    result = []
    currN = high
    for i in range(N - 1, -1, -1):
        if array[i] > currN:
            result.append('/')
            currN = high
        currN -= array[i]
        result.append(str(array[i]))
    result.reverse()
    c = Counter(result)
    if c['/'] < K - 1:
        for i in range(K - 1 - c['/']):
            for j in range(len(result)):
                if result[j] != '/' and result[j + 1] != '/':
                    result.insert(j + 1, '/')
                    break

    print(high)
    return ' '.join(result)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for itertest in range(self.numOfTests):
            N, K = map(int, self.fIn.readline().strip().split())
            array = map(int, self.fIn.readline().split())
            self.input.append((N, K, array))

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
