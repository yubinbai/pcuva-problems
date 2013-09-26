import sys

sys.stdin = open('input.txt')
MAXN = 300
fact = [1]
for i in range(1, MAXN * 3):
    fact.append(i * fact[-1])
while True:
    n = int(input())
    if not n:
        break
    print fact[2 * n] / fact[n + 1]
