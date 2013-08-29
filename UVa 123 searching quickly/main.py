import sys
from collections import defaultdict

sys.stdin = open('input.txt')
ignored = set()
while True:
    line = raw_input().strip()
    if line == '::':
        break
    ignored.add(line.lower())

sort = defaultdict(list)
while True:
    try:
        line = raw_input().strip()
    except:
        break
    lineList = line.lower().split()
    for i, w in enumerate(lineList):
        if w not in ignored:
            list2 = list(lineList)
            list2[i] = w.upper()
            sort[w].append(' '.join(list2))
keys = sort.keys()
keys.sort()
for k in keys:
    for line in sort[k]:
        print line
