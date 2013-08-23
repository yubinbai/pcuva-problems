import sys
import re

sys.stdin = open('input.txt')
while True:
    try:
        K, E = map(int, raw_input().split())
    except:
        break
    keys = set()
    for i in range(K):
        keys.add(raw_input().strip())
    maxCounter = 0
    worstW = []
    for i in range(E):
        line = raw_input().strip()
        words = re.findall('[a-zA-z]+', line)
        counter = 0
        for w in words:
            if w.lower() in keys:
                counter += 1
        if counter > maxCounter:
            maxCounter = counter
            worstW = [line]
        elif counter == maxCounter:
            worstW.append(line)
    print '\n'.join(worstW)
