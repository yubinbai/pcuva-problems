import sys
import tools_karkkainen_sanders as tks


def longest(s):
    n = len(s)
    ns, sa = tks.simple_kark_sort(s)
    lcp = tks.LCP(s, sa)
    maxI, maxV = -1, -1
    for i, v in enumerate(lcp):
        if v > maxV:
            maxI, maxV = i, v
    count = 1
    for i, v in enumerate(lcp):
        if s[sa[i]] == s[sa[maxI]] and v == maxV:
            count += 1
    return count, s[sa[maxI]:sa[maxI] + maxV]

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    n, s = longest(line)
    if len(s) == 0:
        print('No repetitions found!')
    else:
        print('%s %d' % (s, n))
