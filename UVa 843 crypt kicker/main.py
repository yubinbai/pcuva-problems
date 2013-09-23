import sys
import itertools

sys.stdin = open('input.txt')
nW = int(input())
words = []
for x in xrange(nW):
    words.append(raw_input().strip())
words = set(words)
wDict = {}
for k, g in itertools.groupby(words, key=len):
    wDict[k] = list(g)


def backtrack(step):
    if step == len(line):
        result[0] = ' '.join(path)
        return
    for w in wDict[len(line[step])]:
        flag = True
        for i, c in enumerate(w):
            if crypt[c] and crypt[c] != line[step][i]:
                flag = False
                break
        if not flag:
            continue
        tempCrypt = dict(crypt)
        for i, c in enumerate(w):
            crypt[c] = line[step][i]
        path.append(w)
        backtrack(step + 1)
        for c in crypt:
            crypt[c] = tempCrypt[c]
        path.pop()


while True:
    try:
        line = raw_input().strip().split()
    except:
        break
    crypt = dict((chr(i), None) for i in range(ord('a'), ord('z') + 1))
    path = []
    result = [None]
    backtrack(0)
    if result[0]:
        print result[0]
    else:
        print ' '.join('*' * len(w) for w in line)
