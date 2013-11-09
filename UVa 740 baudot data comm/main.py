import sys

sys.stdin = open('input.txt')
down = raw_input().strip('\n')
up = raw_input().strip('\n')
while True:
    try:
        s = raw_input().strip()
    except:
        break
    res = []
    isDown = True
    for i in range(0, len(s), 5):
        w = int(s[i:i + 5], 2)
        if w == int('11011', 2):
            isDown = True
            continue
        if w == int('11111', 2):
            isDown = False
            continue
        if isDown:
            res.append(down[w])
        else:
            res.append(up[w])
    print ''.join(res)
