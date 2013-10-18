import sys
import collections

sys.stdin = open('input.txt')
cases = int(input())
for _ in range(cases):
    raw_input()
    nCand = int(input())
    relations = {}
    for _ in range(nCand):
        k = raw_input().strip()
        v = raw_input().strip()
        relations[k] = v
    nVotes = int(input())
    votes = []
    for _ in range(nVotes):
        votes.append(raw_input().strip())
    c = collections.Counter(votes)
    a, b = c.most_common(2)
    if a[1] == b[1]:
        print 'tie'
    else:
        print relations[a[0]]
