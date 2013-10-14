import sys

sys.stdin = open('input.txt')
d = {}
while True:
    s = raw_input().strip()
    if s == '':
        break
    x, y = s.split()
    d[y] = x
while True:
    try:
        s = raw_input().strip()
    except:
        break
    try:
        print d[s]
    except:
        print 'eh'
