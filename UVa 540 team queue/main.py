import sys
from collections import deque
from numpypy import *

MAXN = 1000005
sys.stdin = open('input.txt')
while True:
    T = int(input())
    if not T:
        break
    teamOf = zeros((MAXN), dtype=int16)
    for t in range(T):
        line = map(int, raw_input().split())
        for m in line[1:]:
            teamOf[m] = t
    totalQ = deque()
    teamQ = []
    for i in range(T):
        teamQ.append(deque())
    while True:
        command = raw_input().strip().split()
        if command[0] == 'STOP':
            break
        elif command[0] == 'ENQUEUE':
            m = int(command[1])
            t = teamOf[m]
            if teamQ[t]:
                teamQ[t].append(m)
            else:
                teamQ[t].append(m)
                totalQ.append(teamQ[t])
        elif command[0] == 'DEQUEUE':
            t = totalQ.popleft()
            print t.popleft()
            if t:
                totalQ.appendleft(t)
