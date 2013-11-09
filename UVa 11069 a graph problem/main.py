import sys

memo = [1, 1, 2]
for x in range(3, 100):
    memo.append(memo[x - 2] + memo[x - 3])

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    print memo[n]
