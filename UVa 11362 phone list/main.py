import sys

sys.stdin = open('input.txt')
for _ in range(int(input())):
    p = []
    for _ in range(int(input())):
        p.append(raw_input().strip())
    p.sort()
    flag = True
    for i in range(len(p) - 1):
        for j in range(i + 1, len(p)):
            if len(p[i]) < len(p[j]) and p[i] == p[j][:len(p[i])]:
                flag = False
                break
        if not flag:
            break
    if flag:
        print 'YES'
    else:
        print 'NO'
