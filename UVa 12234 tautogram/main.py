import sys

sys.stdin = open('input.txt')
while True:
    line = raw_input().strip()
    if line == '*':
        break
    c = line[0].lower()
    if all([w[0].lower() == c for w in line.split()]):
        print 'Y'
    else:
        print 'N'
