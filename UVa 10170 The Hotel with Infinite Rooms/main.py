import sys
import bisect

sys.stdin = open('input.txt')
totals = [0]
for i in range(1, 10001):
    totals.append(totals[-1] + i)
while True:
    try:
        s, d = map(int, raw_input().split())
    except:
        break
    idx = bisect.bisect_left(totals, d + totals[s - 1])
    print idx
