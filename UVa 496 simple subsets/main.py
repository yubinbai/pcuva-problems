import sys

sys.stdin = open('input.txt')
while True:
    try:
        A = set(raw_input().strip().split())
        B = set(raw_input().strip().split())
    except:
        break
    a = A & B
    if A == B:
        print 'A equals B'
    elif a == A:
        print 'A is a proper subset of B'
    elif a == B:
        print 'B is a proper subset of A'
    elif not a:
        print 'A and B are disjoint'
    else:
        print 'I\'m confused!'

