import sys
import re
import collections


def lenChars(s):
    return len(re.findall('[a-zA-Z]', s))

sys.stdin = open('input.txt')
s = []
while True:
    try:
        line = raw_input().strip()
    except:
        break
    if line != '#':
        if s and s[-1][-1] == '-':
            s[-1] = s[-1][:-1]
            s.append(line)
        else:
            s.append(' ' + line)
    else:
        s = ''.join(s)
        s = re.split('[ ?!,.]', s)
        # print s, map(lenChars, s)
        c = collections.Counter(map(lenChars, s))
        for i in sorted(c.keys())[1:]:
            print i, c[i]
        print
        s = []
