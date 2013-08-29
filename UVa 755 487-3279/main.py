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
            if c in list('ABC'):
                number.append('2')
            elif c in list('DEF'):
                number.append('3')
            elif c in list('GHI'):
                number.append('4')
            elif c in list('JKL'):
                number.append('5')
            elif c in list('MNO'):
                number.append('6')
            elif c in list('PRS'):
                number.append('7')
            elif c in list('TUV'):
                number.append('8')
            elif c in list('WXY'):
                number.append('9')
            elif c in list('1234567890'):
                number.append(c)
        numbers.append(''.join(number))

    counter = Counter(numbers)
    flag = False
    for k, v in counter.items():
        if v >= 2:
            flag = True
            print k[:3] + '-' + k[3:] + ' ' + str(v)
    if not flag:
        print 'No duplicates.'
