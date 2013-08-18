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
    N, code = par

    def decode(code):
        '''
        return 0 when bad code
        return 1 when bad c
        return 2 when bad k
        otherwise good results
        '''
        intensities = set(code)
        if len(intensities) < 2:
            return 0
        intensities = sorted(list(intensities))
        for i, v in enumerate(code):
            if v == intensities[0]:
                code[i] = '0'
            elif v == intensities[1]:
                code[i] = '1'
            else:
                return 0
        j = 0
        result = []
        while j < len(code):
            w = ''.join(code[j:j + 5])
            if w not in codeD:
                return 0
            else:
                result.append(codeD[w])
            j += 6
        if result[0] != 's' or result[-1] != 's':
            return 0

        # get C value
        n = len(result) - 4
        s = sum(((n - i) % 10 + 1) * wtD[result[i]]
                for i in range(1, n + 1)) % 11
        if str(s) != result[-3]:
            return 1
        # get K value
        s = sum(((n - i + 1) % 9 + 1) * wtD[result[i]]
                for i in range(1, n + 2)) % 11
        if str(s) != result[-2]:
            return 2
        return ''.join(result[1:-3])

    c1 = decode(code)
    if c1 not in range(3):
        return c1
    code.reverse()
    c2 = decode(code)
    if c2 not in range(3):
        return c2
    if c1 == 1 or c2 == 1:
        return 'bad C'
    if c1 == 2 or c2 == 2:
        return 'bad K'
    return 'bad code'


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        while True:
            N = int(self.fIn.readline())
            if N == 0:
                break
            self.numOfTests += 1
            code = []
            while True:
                line = self.fIn.readline()
                if line == '\n':
                    break
                code.extend(line.split())
            self.input.append((N, code))

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
