import sys

sys.stdin = open('input.txt')
numTest = int(input())
for x in range(numTest):
    raw_input()
    n = int(input())
    left, right = 1, 1 << 4000
    while left < right - 1:
        mid = (left + right) >> 1
        sq = mid ** 2
        if sq > n:
            right = mid
        elif sq < n:
            left = mid
        else:
            print mid
            break
