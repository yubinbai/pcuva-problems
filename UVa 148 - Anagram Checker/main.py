'''
Created on Jul 30, 2013
@author: Yubin Bai
All rights reserved.
'''
import sys
from numpypy import *
parallelSolve = False


def solve(ph):

    def match(i):
        for x in range(26):
            if wordMat[i, x] > phraseCount[x]:
                return False
        return True

    def backtrack(currW):
        if sum(phraseCount) == 0:
            results.append(list(path))
            return
        for i in range(currW + 1, N):
            if match(i):
                for j in range(26):
                    phraseCount[j] -= wordMat[i, j]
                path.append(i)
                backtrack(i)
                for j in range(26):
                    phraseCount[j] += wordMat[i, j]
                path.pop()
    path = []
    phraseCount = [0] * 26
    for c in ph:
        if c in alphabet:
            phraseCount[alphabet[c]] += 1
    results = []
    backtrack(0)
    resultStr = []
    for row in results:
        resultStr.append(ph + ' == ' + ' '.join(words[i] for i in row))
    if resultStr:
        return '\n'.join(resultStr)
    else:
        return ''


sys.stdin = open('input.txt')
words = []
phrases = []
while True:
    line = raw_input().strip()
    if line[0] == '#':
        break
    else:
        words.append(line)
while True:
    line = raw_input().strip()
    if line[0] == '#':
        break
    else:
        phrases.append(line)
N = len(words)
M = 26  # 0-25 is alphabet
alphabet = {}
for e in range(ord('A'), ord('Z') + 1):
    alphabet[chr(e)] = e - ord('A')

wordMat = zeros((N, M), dtype=byte)
for i, w in enumerate(words):
    for c in w:
        if c in alphabet:
            wordMat[i, alphabet[c]] += 1

for ph in phrases:
    print(solve(ph))
