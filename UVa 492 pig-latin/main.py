import re
import sys

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip()
    except:
        break
    words = re.findall('[a-zA-Z]+', line)
    seps = re.split('[a-zA-Z]+', line)
    result = []
    for i, w in enumerate(words):
        if w[0] in set('aeiouAEIOU'):
            result.append(w + 'ay')
        else:
            result.append(w[1:] + w[0] + 'ay')
        result.append(seps[i + 1])
    print ''.join(result)
