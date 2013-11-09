import sys

sys.stdin = open('input.txt')
for case in range(1, 1 + int(input())):
    c, d = map(int, raw_input().split())
    print 'Case %d: %.2f' % (case, c + d * 5.0 / 9.0)
