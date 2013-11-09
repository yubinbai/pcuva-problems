import sys

sys.stdin = open('input.txt')
while True:
    d, s = raw_input().strip().split()
    if d == '0' and s == '0':
        break
    s = ''.join(filter(lambda c: c != d, s))
    if s != '':
        print int(s)
    else:
        print 0
