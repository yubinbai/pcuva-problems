import sys

sys.stdin = open('input.txt')
val = map(lambda x: 3 ** x, range(0, 92))
while True:
    n = int(input())
    if not n:
        break
    n -= 1
    result = [val[i] for i in range(len(bin(n)) - 2) if n & (1 << i)]
    print '{ ' + ', '.join(map(str, result)) + ' }'
