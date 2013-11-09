import sys
import re

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().rstrip('\n')
    except:
        break
    s = re.findall(' +', line)
    l = max(map(len, s))
    c = 0
    while l >= 2:
        c += 1
        l = sum(divmod(l, 2))
    print c
