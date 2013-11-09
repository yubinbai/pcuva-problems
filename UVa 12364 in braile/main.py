import sys

dMap = [
    ['.*', '*.', '*.', '**', '**', '*.', '**', '**', '*.', '.*'],
    ['**', '..', '*.', '..', '.*', '.*', '*.', '**', '**', '*.'],
    ['..', '..', '..', '..', '..', '..', '..', '..', '..', '..']]

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    if raw_input().strip() == 'S':
        s = raw_input().strip()
        res = [[], [], []]
        for d in s:
            for i in range(3):
                res[i].append(dMap[i][int(d)])
        for i in range(3):
            print ' '.join(res[i])
    else:
        b = []
        for i in range(3):
            b.append(raw_input().strip().split())
        res = []
        for k in range(n):
            for d in range(10):
                flag = True
                for x in range(3):
                    if dMap[x][d] != b[x][k]:
                        flag = False
                        break
                if flag:
                    res.append(d)
                    break
        print ''.join(map(str, res))
