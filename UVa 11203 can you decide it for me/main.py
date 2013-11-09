import sys


def isTheorem(s):
    try:
        x, r = s.split('M')
    except:
        return False
    if x != '?' * len(x):
        return False
    try:
        y, z = r.split('E')
    except:
        return False
    if y != '?' * len(y):
        return False
    if z != '?' * len(z):
        return False
    if len(x) == 0 or len(y) == 0 or len(x) != len(z) - len(y):
        return False
    return True


sys.stdin = open('input.txt')
for _ in range(int(input())):
    s = raw_input().strip()
    if isTheorem(s):
        print 'theorem'
    else:
        print 'no-theorem'
