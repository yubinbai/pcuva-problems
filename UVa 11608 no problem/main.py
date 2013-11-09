import sys

sys.stdin = open('input.txt')
case = 0
while True:
    remain = int(input())
    if remain == -1:
        break
    case += 1
    print 'Case %d:' % case
    p = map(int, raw_input().split())
    d = map(int, raw_input().split())
    for i in range(len(p)):
        if remain < d[i]:
            print 'No problem. :('
            remain += p[i]
        else:
            print 'No problem! :D'
            remain += p[i] - d[i]
