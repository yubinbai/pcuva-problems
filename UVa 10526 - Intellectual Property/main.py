import tools_karkkainen_sanders as tks
import sys

sys.stdin = open('input.txt')
caseNumber = 1
while True:
    K = int(input())
    if K == 0:
        break
    print '\nCase#%d' % caseNumber
    caseNumber += 1
    tdpStr = []
    raw_input()
    while True:
        line = raw_input().strip()
        if line == 'END TDP CODEBASE':
            break
        tdpStr.append(line + '\n')
    jcnStr = []
    raw_input()
    while True:
        line = raw_input()
        if line.strip() == 'END JCN CODEBASE':
            break
        jcnStr.append(line + '\n')
    N = len(''.join(jcnStr))
    M = len(''.join(tdpStr))
    S = ''.join(jcnStr) + '$' + ''.join(tdpStr)

    SA = tks.simple_kark_sort(S)
    LCP = tks.LCP(S, SA)

    sortedLCP = []
    L = N + M + 1
    for i in range(L):
        for j in range(i, L):
            begin = SA[i]
            end = SA[j + 1]
            if (begin > N and end < N) or (begin < N and end > N):
                sortedLCP.append((-1 * min(LCP[i:j + 1]), min(begin, end)))

    sortedLCP.sort()
    used = []
    for dup in sortedLCP:
        if K == 0:
            break
        sLen, begin = dup
        if begin > N:
            break
        sLen *= -1
        if sLen <= 0:
            break
        end = begin + sLen
        flag = True
        for row in used:
            if begin >= row[0] and begin <= row[1] and end >= row[0] and end <= row[1]:
                flag = False
        if flag:
            print 'Len: %d Pos %d\n %s' % (sLen, begin, S[begin:end])
            used.append((begin, end))
            K -= 1
