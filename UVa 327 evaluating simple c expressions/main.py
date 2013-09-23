import sys
import re

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip().replace(' ', '')
    except:
        break
    symbols = dict([(chr(i + ord('a') - 1), i) for i in range(1, 27)])
    addBefore = re.findall('\+\+[a-z]', line)
    for w in addBefore:
        symbols[w[-1]] += 1
    subBefore = re.findall('--[a-z]', line)
    for w in subBefore:
        symbols[w[-1]] -= 1
    addAfter = re.findall('[a-z]\+\+', line)
    subAfter = re.findall('[a-z]--', line)

    line = line.replace('++', '').replace('--', '')
    currsign = 1
    result = 0
    for c in line:
        if c == '+':
            currsign = 1
        elif c == '-':
            currsign = -1
        else:
            result += currsign * symbols[c]

    print 'result is :%d' % result
    for w in addAfter:
        symbols[w[0]] += 1
    for w in subAfter:
        symbols[w[0]] -= 1
    resultSym = []
    for c in line:
        if c != '+' and c != '-':
            resultSym.append((c, str(symbols[c])))
    resultSym.sort()
    for s in resultSym:
        print '%s = %s' % s
