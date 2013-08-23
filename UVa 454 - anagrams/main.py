import sys
from itertools import combinations
from collections import defaultdict

sys.stdin = open('input.txt')
numTest = int(input())
raw_input()
for itertest in range(numTest):
    words = defaultdict(list)
    while True:
        try:
            line = raw_input().strip()
        except:
            break
        if not len(line):
            break
        w = list(line)
        w.sort()
        w = ''.join(w).strip()
        words[w].append(line)
    for w in words:
        if len(words[w]) >= 2:
            for w1, w2 in combinations(words[w], 2):
                print '%s = %s' % (w1, w2)
