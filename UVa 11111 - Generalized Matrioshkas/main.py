import sys

sys.stdin = open('input.txt')
while True:
    try:
        queue = map(int, raw_input().split())
    except:
        break
    stack = []
    flag = True
    for q in queue:
        if q < 0:
            if not stack:
                stack.append([q, abs(q)])
                continue
            if stack and stack[-1][1] > abs(q):
                stack[-1][1] -= abs(q)
                stack.append([q, abs(q)])
            else:
                flag = False
                break
        else:
            if not stack or stack[-1][0] != -1 * q:
                flag = False
                break
            else:
                stack.pop()
    # print stack
    if not flag or len(stack) > 0:
        print ':-( Try again.'
    else:
        print ':-) Matrioshka!'
