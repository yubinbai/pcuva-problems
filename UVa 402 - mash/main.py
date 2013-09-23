import sys

sys.stdin = open('input.txt')
while True:
    try:
        line = map(int, raw_input().split())
    except:
        break
    n = line[0]
    x = line[1]
    cards = line[2:]
    q = list(range(1, n + 1))
    flag = False
    for c in cards:
        idx = -1
        while idx + c < len(q):
            idx += c
            del q[idx]
            if len(q) == x:
                flag = True
                break
            idx -= 1
        if flag:
            break
    print q
