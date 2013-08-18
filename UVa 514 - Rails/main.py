import sys
from collections import deque

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    inSeq = map(int, raw_input().split())
    outSeq = map(int, raw_input().split())
    print inSeq, outSeq
    raw_input()

    stack = []
    j = 0
    for e in inSeq:
        if e == outSeq[j]:
            j += 1
        else:
            stack.append(e)
        while stack and stack[-1] == outSeq[j]:
            stack.pop()
            j += 1

    if not stack and j == N:
        print 'Yes'
    else:
        print 'No'
