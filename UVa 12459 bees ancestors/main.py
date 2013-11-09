import sys

sys.stdin = open('input.txt')
memo = [0]
m, f = 0, 1
for _ in range(85):
    memo.append(m + f)
    m, f = f, m + f
while True:
    n = int(input())
    if not n:
        break
    print memo[n]
