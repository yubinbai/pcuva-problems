import sys


def isSimple(w):
    return w == 'A'


def isFull(w):
    if w[-2:] == 'AB':
        return isSimple(w[:-2]) or isFull(w[:-2])
    else:
        return False


def isMuta(w):
    if w[0] == 'B' and w[-1] == 'A':
        return isSimple(w[1:-1]) or isFull(w[1:-1]) or isMuta(w[1:-1])

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    if isSimple(line):
        print 'SIMPLE'
    elif isFull(line):
        print 'FULLY-GROWN'
    elif isMuta(line):
        print 'MUTAGENIC'
    else:
        print 'MUTANT'
