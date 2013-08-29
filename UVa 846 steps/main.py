import sys
from bisect import bisect_left

sys.stdin = open('input.txt')
squares = map(lambda x: x ** 2, range(100000))
numTest = int(input())
for itertest in range(numTest):
    n1, n2 = map(int, raw_input().split())
    diff = n2 - n1
    pos = bisect_left(squares, diff)
    if diff == squares[pos]:
        print pos * 2 - 1
    else:
        if diff - squares[pos - 1] > pos - 1:
            print pos * 2 - 1
        else:
            print pos * 2 - 2
