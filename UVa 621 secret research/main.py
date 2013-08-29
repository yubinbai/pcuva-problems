import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    if line in ['1', '4', '78']:
        print '+'
    elif line[-2:] == '35':
        print '-'
    elif line[0] == '9' and line[-1] == '4':
        print '*'
    elif line[:3] == '190':
        print '?'
    else:
        print '+'
