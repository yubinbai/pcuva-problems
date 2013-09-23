import sys
import re
from collections import Counter

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip()
    except:
        break
    c = Counter(re.findall('[a-zA-Z]', line)).most_common()
    most = c[0][1]
    chars = []
    for k, v in c:
        if v != most:
            break
        else:
            chars.append(k)
    chars.sort()
    print ''.join(chars), most
