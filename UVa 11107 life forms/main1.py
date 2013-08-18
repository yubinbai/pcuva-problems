import karkkainen_sanders as tks
import sys

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if N == 0:
        break
    sStr = []
    for i in range(N):
        line = raw_input().strip()
        for c in line:
            sStr.append(ord(c) + 10000)
            # sStr.append(c)
        sStr.append(i + 100)
        # sStr.append(chr(i + ord('1')))
    # for s in sStr: print ord(s)
    L = len(sStr)
    SA = tks.simple_kark_sort(sStr)
    LCP = tks.LCP(sStr, SA)

    # for v in SA[:L]: print ''.join(sStr[v:])
    # print LCP

    belongLine = [0] * L
    for i, v in enumerate(SA[:L]):
        j = v
        while sStr[j] > 10000:
            j += 1
        belongLine[i] = sStr[j]
    # print belongLine

    # find the start and end
    result = 0
    maxStart = []
    for start in range(0, L - 1):
        usedLine = set()
        usedLine.add(belongLine[start])
        usedLine.add(belongLine[start + 1])
        end = start
        while len(usedLine) < (N + 1) // 2 and end < L:
            usedLine.add(belongLine[end])
            end += 1
        lcp = min(LCP[start:end + 1])
        if result < lcp:
            maxStart, result = [start], lcp
        elif result == lcp:
            maxStart.append(start)

    if result == 0:
        print('?')
    else:
        for start in maxStart:
            rStr = []
            for i in range(SA[start], SA[start] + result):
                rStr.append(unichr(sStr[i] - 10000))
            print(''.join(rStr))
    print('')
