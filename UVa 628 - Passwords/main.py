import sys
from itertools import product

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    words = []
    for x in xrange(1, N + 1):
        words.append(raw_input().strip())
    digits = [str(i) for i in range(10)]
    M = int(input())
    print '--'
    for x in xrange(1, M + 1):
        rule = raw_input().strip()
        par = []
        for c in rule:
            if c == '#':
                par.append(words)
            else:
                par.append(digits)
        for t in product(*par):
            print ''.join(t)
