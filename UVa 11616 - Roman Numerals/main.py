'''
Created on Jun 18, 2013

@author: Yubin Bai

All rights reserved.
'''

import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 30


def solve(par):
    '''
    roman numerals
    '''
    def toDec(number):
        total = 0
        for i, d in enumerate(number):
            if d == 'I':
                if 'V' not in number[i + 1:] and 'X' not in number[i + 1:]:
                    total += 1
                else:
                    total -= 1
            elif d == 'V':
                total += 5
            elif d == 'X':
                if 'L' not in number[i + 1:] and 'C' not in number[i + 1:]:
                    total += 10
                else:
                    total -= 10
            elif d == 'L':
                total += 50
            elif d == 'C':
                if 'D' not in number[i + 1:] and 'M' not in number[i + 1:]:
                    total += 100
                else:
                    total -= 100
            elif d == 'D':
                total += 500
            else:  # 'M'
                total += 1000
        return total

    def toRoman(number):
        result = []
        d1 = {0: '', 1: 'I', 2: 'II', 3: 'III', 4: 'IV',
              5: 'V', 6: 'VI', 7: 'VII', 8: 'VIII', 9: 'IX'}
        result.append(d1[number % 10])
        number -= number % 10
        d2 = {0: '', 10: 'X', 20: 'XX', 30: 'XXX', 40: 'XL',
              50: 'L', 60: 'LX', 70: 'LXX', 80: 'LXXX', 90: 'XC'}
        result.append(d2[number % 100])
        number -= number % 100
        d3 = {0: '', 100: 'C', 200: 'CC', 300: 'CCC', 400: 'CD',
              500: 'D', 600: 'DC', 700: 'DCC', 800: 'DCCC', 900: 'CM'}
        result.append(d3[number % 1000])
        number -= number % 1000
        d4 = {0: '', 1000: 'M', 2000: 'MM', 3000: 'MMM'}
        result.append(d4[number % 10000])
        result.reverse()
        return ''.join(result)

    N = par
    values = [1, 5, 10, 50, 100, 500, 1000]
    if N[0] in list('IVXLCMD'):
        return toDec(N.strip())
    else:
        return toRoman(int(N))


class Solver:

    def getInput(self):
        self.numOfTests = int(self.fIn.readline())
        self.input = []
        for i in range(self.numOfTests):
            self.input.append((self.fIn.readline()))

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
