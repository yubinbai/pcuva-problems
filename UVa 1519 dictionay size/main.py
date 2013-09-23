import sys

sys.stdin = open('input.txt')
n = int(input())
pre = set()
suf = set()
for i in range(n):
    w = raw_input().strip()
    for j in range(len(w)):
        pre.add(w[:j])
        suf.add(w[j:])
# print len(pre), len(suf)
results = set()
for w1 in pre:
    for w2 in suf:
        results.add(w1 + w2)
print len(results)
