import sys
from collections import deque

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip()
    except:
        break
    result = deque()
    currBuffer = []
    tail = True
    for c in line:
        if c == '[':
            if tail == True:
                result.append(''.join(currBuffer))
                currBuffer = []
                tail = False
        elif c == ']':
            if tail == False:
                result.appendleft(''.join(currBuffer))
                currBuffer = []
                tail = True
        else:
            currBuffer.append(c)
    if tail:
        result.append(''.join(currBuffer))
    else:
        result.appendleft(''.join(currBuffer))
    print ''.join(result)
