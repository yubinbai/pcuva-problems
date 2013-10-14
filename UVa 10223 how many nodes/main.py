import sys

sys.stdin = open('input.txt')
catalan = [1]
while catalan[-1] < 1 << 32:
    total = 0
    n = len(catalan)
    for i in range(n):
        total += catalan[i] * catalan[n - 1 - i]
    catalan.append(total)
while True:
    try:
        n = int(input())
    except:
        break
    print catalan.index(n)
