'''
Created on Jul 14, 2013
@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def solve(par):
    K, table1, table2 = par
    col = []
    for i in range(5):
        col1 = list(r[i] for r in table1)
        col1.sort()
        col.append(col1)
    colb = []
    for i in range(5):
        set1 = set(r[i] for r in table2)
        colb.append(set1)
    Kcount = [K]

    def backtrack(step):
        if step == 5:
            if Kcount[0] != 1:
                Kcount[0] -= 1
            else:
                result.append(''.join(path))
            return
        for c in col[step]:
            if c not in colb[step]:
                continue
            path.append(c)
            backtrack(step + 1)
            path.pop()

    result = []
    path = []
    backtrack(0)
    if result:
        return result[0]
    else:
        return 'NO'


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline().strip())
        self.input = []
        for i in range(self.numOfTests):
            K = int(self.fIn.readline().strip())
            table1 = []
            for j in range(6):
                table1.append(self.fIn.readline().strip())
            table2 = []
            for j in range(6):
                table2.append(self.fIn.readline().strip())
            self.input.append((K, table1, table2))

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
