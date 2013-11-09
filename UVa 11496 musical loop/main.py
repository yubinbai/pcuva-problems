import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    a = map(int, raw_input().split())
    counter = 0
    prevCmp = (a[0] < a[n - 1])
    for i in range(n - 1):
        currCmp = (a[i] < a[i + 1])
        if prevCmp ^ currCmp:
            continue
        else:
            counter += 1
        prevCmp = not currCmp
    currCmp = (a[n - 1] < a[0])
    if not (prevCmp ^ currCmp):
        counter += 1
    print counter
