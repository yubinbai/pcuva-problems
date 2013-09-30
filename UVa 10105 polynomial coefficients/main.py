import sys
import operator

sys.stdin = open('input.txt')
fact = [1, 1]
for i in range(2, 15):
    fact.append(fact[-1] * i)
while True:
    try:
        n, k = map(int, raw_input().split())
        coef = map(int, raw_input().split())
    except:
        break
    print fact[n] / reduce(operator.mul, [fact[c] for c in coef])
