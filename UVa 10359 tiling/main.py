import sys

sys.stdin = open('input.txt')
f = []
a, b = 0, 1
for _ in range(300):
    f.append(b)
    a, b = b, 2 * a + b
while True:
    try:
        n = int(input())
    except:
        break
    print f[n]
