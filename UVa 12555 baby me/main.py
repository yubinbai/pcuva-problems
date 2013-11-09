import sys

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    s = raw_input().strip()
    n = []
    for c in s:
        if c <= '9':
            n.append(c)
        else:
            n.append(' ')
    try:
        a, b = map(int, ''.join(n).split())
    except:
        a = int(''.join(n).strip())
        b = 0
    result = a * 0.5 + b * 0.05
    result *= 100
    if result % 10:
        print 'Case %d: %.2f' % (case, result / 100.0)
    elif result % 100:
        print 'Case %d: %.1f' % (case, result / 100.0)
    else:
        print 'Case %d: %.f' % (case, result / 100.0)
