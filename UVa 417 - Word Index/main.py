import sys
from itertools import *
from numpypy import *
INF = 1 << 31

f = open('input.txt', 'r')
alphabet = [chr(i) for i in range(ord('a'), ord('z') + 1)]

words = []
for i in range(1, 6):
    for row in combinations(alphabet, i):
        words.append(''.join(row))
d = {}
for i, w in enumerate(words):
    d[w] = i + 1


for line in f:
    try:
        print(d[line.strip()])
    except:
        print(0)
