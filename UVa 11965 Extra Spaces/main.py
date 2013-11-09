import sys
import re

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    print 'Case %d:' % case
    for _ in range(int(input())):
        s = re.split(' +', raw_input().rstrip('\n'))
        print ' '.join(s)
    print
