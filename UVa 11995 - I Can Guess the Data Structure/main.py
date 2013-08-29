import sys
from collections import deque
from heapq import *

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    stack = []
    queue = deque()
    heap = []
    isStack = isQueue = isHeap = True
    for i in range(N):
        line = map(int, raw_input().split())
        if line[0] == 1:
            stack.append(line[1])
            queue.append(line[1])
            heappush(heap, line[1])
        else:
            a = stack.pop()
            if a != line[1]:
                isStack = False
            a = queue.popleft()
            if a != line[1]:
                isQueue = False
            a = heappop(heap)
            if a != line[1]:
                isHeap = False
    s = sum([isStack, isQueue, isHeap])
    if s >= 2:
        print 'not sure'
    elif s == 0:
        print 'impossible'
    else:
        if isStack:
            print 'stack'
        if isQueue:
            print 'queue'
        if isHeap:
            print 'priority queue'
