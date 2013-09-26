import sys

sys.stdin = open('input.txt')
chars = '0123456789' + 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' + \
    'abcdefghijklmnopqrstuvwxyz'
chars = list(chars)
while True:
    try:
        line = raw_input().strip()
    except:
        break
    a = max(chars.index(c) for c in line) + 1
    print max(a, 2)
