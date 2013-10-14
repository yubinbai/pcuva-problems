import sys
import itertools

sys.stdin = open('input.txt')
while True:
    num = map(int, raw_input().split())
    if not any(num):
        break
    flag = False
    for t in itertools.permutations(num):
        for o1, o2, o3, o4 in itertools.product(['+', '-', '*'], repeat=4):
            s = '(((%d %s %d) %s %d) %s %d) %s %d' % (
                t[0], o1, t[1], o2, t[2], o3, t[3], o4, t[4])
            if eval(s) == 23:
                flag = True
                break
        if flag:
            break
    if flag:
        print 'Possible'
    else:
        print 'Impossible'
