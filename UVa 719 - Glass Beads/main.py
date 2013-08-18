import tools_karkkainen_sanders as tks
import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    SA = tks.simple_kark_sort(line)
    result = line[SA[0]:] + line[:SA[0]]
    resultIdx = SA[0]
    for v in SA:
        result2 = line[v:] + line[:v]
        print result
        print result2
        if result2 <= result:
            result = result2
            resultIdx = min(resultIdx, v)
        else:
            break
    print resultIdx + 1
