import sys
import re

sys.stdin = open('input.txt')
p, g = map(int, raw_input().split())
names = {}
for _ in range(p):
    a, b = raw_input().strip().split()
    names[a.strip()] = float(b)
for case in range(1, 1 + g):
    inp = raw_input().strip()
    sg = re.split('<|>|=|<=|>=', inp)[0].strip()
    s = sum(names[a.strip()] for a in sg.split('+'))
    exp = inp.replace(' = ', '==').replace(sg, str(s))
    if eval(exp):
        print 'Case #%d was correct.' % case
    else:
        print 'Case #%d was incorrect.' % case
