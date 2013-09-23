import sys
from itertools import combinations

sys.stdin = open('input.txt')
while True:
    try:
        eq = raw_input().split()
    except:
        break
    N = len(eq) >> 1
    left = 1
    leftFlag = True
    numbers = []
    leftPos = [0]
    rightPos = []
    for i, w in enumerate(eq):
        if w == '+' or w == '-':
            if leftFlag and w == '+' or (not leftFlag and w == '-'):
                left += 1
                leftPos.append(i + 1)
            else:
                rightPos.append(i + 1)
        elif w == '=':
            leftFlag = False
            rightPos.append(i + 1)
        else:
            numbers.append(int(w))
    total = sum(numbers)
    if total & 1:
        print 'no solution'
    else:
        for c in combinations(numbers, left):
            if sum(c) == total / 2:
                result = list(eq)
                for i, v in enumerate(leftPos):
                    result[v] = str(c[i])
                remains = list(set(numbers) - set(c))
                for i, v in enumerate(rightPos):
                    result[v] = str(remains[i])
                print ' '.join(result)
                break
