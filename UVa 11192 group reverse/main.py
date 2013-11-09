import sys

sys.stdin = open('input.txt')
while True:
    try:
        n, s = raw_input().strip().split()
    except:
        break
    n = len(s) // int(n)
    result = []
    for i in range(len(s) // n + 1):
        result.append(s[i * n:i * n + n][::-1])
    print ''.join(result)
