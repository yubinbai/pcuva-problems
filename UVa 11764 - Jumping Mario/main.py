import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    A = map(int, raw_input().split())
    low, high = 0, 0
    for i in range(1, N):
        if A[i] > A[i - 1]:
            high += 1
        elif A[i] < A[i - 1]:
            low += 1
    print high, low
