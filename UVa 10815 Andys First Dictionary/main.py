import sys
import re

inFile = open('input.txt')
s = inFile.read()
allWords = re.findall('[a-zA-Z]+', s)
wordSet = set()
for w in allWords:
    wordSet.add(w.lower())
wordList = list(wordSet)
wordList.sort()
print '\n'.join(wordList)
