'''
Created on 2013-6-6

@author: Yubin Bai
'''
import time
from multiprocessing.pool import Pool
parallelSolve = False
INF = 1 << 31


def lexicographically_next_permutation(a):
    """
    Generates the lexicographically next permutation.

    Input: a permutation, called "a". This method modifies
    "a" in place. Returns True if we could generate a next
    permutation. Returns False if it was the last permutation
    lexicographically.
    """
    i = len(a) - 2
    while not (i < 0 or a[i] < a[i + 1]):
        i -= 1
    if i < 0:
        return False
    j = len(a) - 1
    while not (a[j] > a[i]):
        j -= 1
    a[i], a[j] = a[j], a[i]        # swap
    a[i + 1:] = reversed(a[i + 1:])
    # reverse elements from position i+1 till the end of the sequence
    return True


def f(s):
    m = INF
    for i in range(1, len(s)):
        m = min(m, abs(ord(s[i - 1]) - ord(s[i])))
    return m


def solve(par):
    line = par
    word = list(line)
    negativeWord = [-1 * ord(e) for e in word]
    candidates = []
    for i in range(10):
        lexicographically_next_permutation(negativeWord)
        prev = [chr(-1 * e) for e in negativeWord]
        candidates.append(''.join(prev))
    candidates.reverse()
    candidates.append(line)
    for i in range(10):
        lexicographically_next_permutation(word)
        candidates.append(''.join(word))

    m, mStr = -1, ''
    for c in candidates:
        if f(c) > m:
            mStr = c
            m = f(c)
    return mStr + str(m)


class Solver:

    def getInput(self):
        self.numOfTests = 0
        self.input = []
        for line in self.fIn:
            if line == '':
                break
            self.numOfTests += 1
            self.input.append(line.strip())

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
