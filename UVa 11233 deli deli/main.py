import sys
import re

sys.stdin = open('input.txt')
d, n = map(int, raw_input().split())
irreg = {}
for _ in range(d):
    a, b = raw_input().strip().split()
    irreg[a] = b
for _ in range(n):
    w = raw_input().strip()
    if w in irreg:
        print irreg[w]
    elif re.match('.*[^aeiou]y$', w):
        print w[:-1] + 'ies'
    elif re.match('.*o$|.*s$|.*ch$|.*sh$|.*x$', w):
        print w + 'es'
    else:
        print w + 's'
