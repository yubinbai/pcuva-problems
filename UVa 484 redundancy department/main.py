import sys

sys.stdin = open('input.txt')
counter = {}
seq = []
while True:
    try:
        line = map(int, raw_input().split())
    except:
        break
    for n in line:
        try:
            counter[n] += 1
        except:
            counter[n] = 1
            seq.append(n)
for n in seq:
    print n, counter[n]
