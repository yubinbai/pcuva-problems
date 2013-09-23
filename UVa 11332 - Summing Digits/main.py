import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if not N:
        break
    strN = str(N)
    while len(strN) > 1:
        N = sum(int(i) for i in strN)
        strN = str(N)
    print strN
