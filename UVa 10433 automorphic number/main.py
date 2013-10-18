import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    l = len(str(n))
    if pow(n, 2, 10 ** l) == n:
        print 'Automorphic number of %d-digit.' % l
    else:
        print 'Not an Automorphic number.'
