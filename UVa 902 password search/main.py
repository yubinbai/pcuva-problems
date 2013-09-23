import sys
from collections import Counter

sys.stdin = open('input.txt')
while True:
    try:
        size, line = raw_input().strip().split()
    except:
        break
    size = int(size)
    L = len(line)
    c = []
    for i in range(0, L - 2):
        c.append(line[i:i + 3])
    c = Counter(c)
    print c.most_common(1)[0][0]
