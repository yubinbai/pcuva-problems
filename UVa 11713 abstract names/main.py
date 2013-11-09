import sys
import re

sys.stdin = open('input.txt')
for _ in range(int(input())):
    s1 = re.split('[aeiou]', raw_input().strip())
    s2 = re.split('[aeiou]', raw_input().strip())
    if s1 == s2:
        print 'Yes'
    else:
        print 'No'
