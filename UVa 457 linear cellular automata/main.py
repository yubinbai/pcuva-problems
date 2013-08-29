import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    DNA = map(int, raw_input().split())
    currLevel = [0] * 42
    currLevel[20] = 1
    nextLevel = list(currLevel)
    s = {0: ' ', 1: '.', 2: 'x', 3: 'W'}
    for day in range(50):
        print ''.join([s[i] for i in currLevel])
        for i in range(1, 41):
            nextLevel[i] = DNA[
                sum([currLevel[i - 1], currLevel[i], currLevel[i + 1]])]
        currLevel, nextLevel = nextLevel, currLevel
