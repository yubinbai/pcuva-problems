import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    replace = []
    for i in range(N):
        w1 = raw_input().strip()
        w2 = raw_input().strip()
        replace.append((w1, w2))
    line = raw_input().strip()
    for w1, w2 in replace:
        while True:
            index = line.find(w1)
            if index != -1:
                line = line.replace(w1, w2)
            else:
                break
    print line