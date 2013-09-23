import sys

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    P = raw_input().strip()
    L = len(P)
    remains = 0
    for x in range(L):
        remains = (remains * 10 + 1) % N
    print remains
