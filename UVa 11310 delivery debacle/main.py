import sys

sys.stdin = open('input.txt')
memo = [0, 1, 5, 11]
for n in range(4, 41):
    a = memo[-1] + 4 * memo[-2] + 2 * memo[-3]
    memo.append(a)
for _ in range(int(input())):
    print memo[int(input())]
