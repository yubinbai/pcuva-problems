import sys
import collections

sys.stdin = open('input.txt')
fact = [0, 1]
for x in xrange(2, 21):
    fact.append(x * fact[-1])
n = int(input())
for case in range(1, n + 1):
    s = raw_input().strip()
    c = collections.Counter(s)
    total = fact[len(s)]
    for k, v in c.items():
        total /= fact[v]
    print 'Data set %d: %d' % (case, total)
