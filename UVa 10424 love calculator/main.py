import sys
import re

sys.stdin = open('input.txt')
while True:
    try:
        s1 = raw_input().strip()
        s2 = raw_input().strip()
    except:
        break
    t1 = sum(ord(c) - ord('a') + 1 for c in re.findall('[a-z]', s1.lower()))
    while t1 >= 10:
        t1 = sum(int(c) for c in str(t1))
    t2 = sum(ord(c) - ord('a') + 1 for c in re.findall('[a-z]', s2.lower()))
    while t2 >= 10:
        t2 = sum(int(c) for c in str(t2))
    print '%.2f %%' % (100.0 * t2 / t1)
