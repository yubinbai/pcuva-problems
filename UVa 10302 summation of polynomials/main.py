import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    n += 1
    print((n - 1) ** 2 * n ** 2 / 4)
    # print n * (n - 1) * (n - 2) * (n - 3) / 4 + n * (n - 1) * (n - 2) + n *
    # (n - 1) / 2
