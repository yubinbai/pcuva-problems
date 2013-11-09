import sys


def isMod17(n):
    if n > 100:
        return isMod17(n // 10 - 5 * (n % 10))
    else:
        return n % 17 == 0

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    if isMod17(n):
        print 1
    else:
        print 0
