import sys

sys.stdin = open('input.txt')
memo = [0, 0, 0, 0, 1]
for n in range(5, 1000005):
    if n & 1:
        r = (n - 1) * ((n - 3) / 2) / 2
    else:
        r = (n - 2) * (n / 2 - 1) / 2
    memo.append(memo[-1] + r)
for _ in range(int(input())):
    print memo[int(input())]
