import sys

sys.stdin = open('input.txt')
memo = [0] * 40
memo[0] = 1
for i in range(35):
    memo[i + 2] += 3 * memo[i]
    for j in range(4, 40 - i, 2):
        memo[i + j] += 2 * memo[i]
while True:
    n = int(input())
    if n != -1:
        print memo[n]
    else:
        break
