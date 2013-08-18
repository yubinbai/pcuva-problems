import sys
from itertools import permutations
INF = 1 << 30

inFile = open('input.txt')
binName = 'BGC'
for line in inFile:
    row = map(int, line.split())
    currP, currMin = '', INF

    for p in permutations([0, 1, 2]):
        total = 0
        for i in range(3):
            for j in range(3):
                if j != p[i]:
                    total += row[i * 3 + j]
        name1 = ''.join(binName[i] for i in p)
        if total < currMin:
            currP, currMin = name1, total
        elif total == currMin:
            currP = min(currP, name1)
    print('%s %d' % (currP, currMin))
