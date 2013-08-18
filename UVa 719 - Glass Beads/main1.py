import tools_karkkainen_sanders as tks
import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    m = len(line)
    line = line * 2
    SA = tks.simple_kark_sort(line)
    for v in SA:
        if v < m:
            print v + 1
            break
