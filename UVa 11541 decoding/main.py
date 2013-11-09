import sys

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    s = raw_input().strip()
    res = []
    currC = ''
    count = 0
    for c in s:
        if c in set('0123456789'):
            count *= 10
            count += int(c)
        else:
            res.append(currC * count)
            currC = c
            count = 0
    res.append(currC * count)
    print 'Case %d: %s' % (case, ''.join(res))
