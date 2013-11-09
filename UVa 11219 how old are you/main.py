import sys

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    raw_input()
    d1, m1, y1 = map(int, raw_input().strip().split('/'))
    d2, m2, y2 = map(int, raw_input().strip().split('/'))
    print 'Case #%d' % case,
    if (y1, m1, d1) < (y2, m2, d2):
        print 'Invalid birth date'
    else:
        age = y1 - y2 - 1 + int((m1, d1) >= (m2, d2))
        if age > 130:
            print 'Check birth date'
        else:
            print age
