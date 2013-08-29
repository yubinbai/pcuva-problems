import sys
from collections import Counter

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    raw_input()
    N = int(input())
    numbers = []
    for i in range(N):
        line = raw_input().strip()
        number = []
        for c in line:
            c1 = c
            if c1.isalpha():
                if c1 > 'Q':
                    c1 = chr(ord(c1) - 1)
                c1 = chr((ord(c1) - ord('A')) / 3 + 2 + ord('0'))
            if c1.isdigit():
                number.append(c1)
        numbers.append(''.join(number))

    counter = Counter(numbers)
    flag = False
    for k, v in counter.items():
        if v >= 2:
            flag = True
            print k[:3] + '-' + k[3:] + ' ' + str(v)
    if not flag:
        print 'No duplicates.'
