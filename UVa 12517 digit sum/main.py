import sys

sys.stdin = open('input.txt')
memo = [0]
for i in range(1, 10000001):
    s = sum(map(int, str(i)))
    memo.append(memo[-1] + s)
while True:
    i, j = map(int, raw_input().split())
    if not i and not j:
        break
    print memo[j] - memo[i - 1]
