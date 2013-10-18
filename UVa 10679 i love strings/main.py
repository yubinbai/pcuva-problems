import sys
import re

sys.stdin = open('input.txt')
for _ in range(int(input())):
    s = raw_input().strip()
    for _ in range(int(input())):
        if re.search(raw_input().strip(), s):
            print 'y'
        else:
            print 'n'
