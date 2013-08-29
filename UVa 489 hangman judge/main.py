import sys
from collections import Counter

sys.stdin = open('input.txt')
while True:
    N = int(input())
    if -1 == N:
        break
    print 'Round %d' % N
    target = raw_input().strip()
    guess = raw_input().strip()
    counter = Counter(target)
    remain = len(target)
    hangCount = 0
    for g in guess:
        if g in counter:
            remain -= counter[g]
            counter[g] = 0
            if remain == 0:
                print 'You win.'
                break
        else:
            hangCount += 1
            if hangCount == 7:
                print 'You lose.'
                break
    if remain != 0 and hangCount != 7:
        print 'You chickend out.'
