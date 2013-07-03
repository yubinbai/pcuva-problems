''' Created on 2013-6-6

@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31

codeD = {'00001': '0', '10001': '1', '01001': '2', '11000': '3', '00101': '4', '10100':
         '5', '01100': '6', '00011': '7', '10010': '8', '10000': '9', '00100': '-', '00110': 's'}
wtD = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
       '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, '-': 10}


def solve(par):
    pos, array = par
    array1 = [0.0] * len(array)
    for i, p in enumerate(pos):
        array1[p - 1] = array[i]
    return '\n'.join(str(e) for e in array1)


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            self.fIn.readline()
            pos = map(int, self.fIn.readline().split())
            array = map(float, self.fIn.readline().split())
            self.input.append((pos, array))

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
