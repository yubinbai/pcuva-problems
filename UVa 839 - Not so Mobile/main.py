import sys
from collections import namedtuple


def weight():
    b = balances[currLine[0]]
    wl, dl, wr, dr = b
    correct1 = correct2 = True
    if not wl:
        currLine[0] += 1
        correct1, wl = weight()
    if not wr:
        currLine[0] += 1
        correct2, wr = weight()
    if wl * dl == wr * dr and correct1 and correct2:
        return True, wl + wr
    else:
        return False, -1

sys.stdin = open('input.txt')
numTest = int(input())
raw_input()
for itertest in range(numTest):
    balances = []
    while True:
        try:
            line = raw_input().strip()
        except:
            break
        if line == '':
            break
        balances.append(map(int, line.split()))
    currLine = [0]
    correct, w = weight()
    if correct:
        print 'YES'
    else:
        print 'NO'
