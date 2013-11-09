import sys

MAXN = 1000005
sys.stdin = open('input.txt')
while True:
    try:
        inp = map(int, raw_input().split())
    except:
        break
    n = inp[0]
    arr = inp[2:]
    win = [0] * (n + 1)
    for i in range(1, n + 1):
        for a in arr:
            if i >= a and not win[i - a]:
                win[i] = 1
    if win[n]:
        print 'Stan wins'
    else:
        print 'Ollie wins'
