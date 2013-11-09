import sys

sys.stdin = open('input.txt')
cases = int(input())
raw_input()
for case in range(1, 1 + cases):
    print 'Case #%d:' % case
    while True:
        try:
            line = raw_input().strip()
        except:
            break
        if line == '':
            break
        line = line.split()
        i = 0
        res = []
        for w in line:
            if i < len(w):
                res.append(w[i])
                i += 1
        print ''.join(res)
    if case != cases:
        print
