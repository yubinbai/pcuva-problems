import sys

sys.stdin = open('input.txt')
while True:
    line = raw_input().strip()
    if line == '0':
        break
    line = line[::-1]
    result = 0
    for i, v in enumerate(line):
        result += int(v) * ((1 << (i + 1)) - 1)
    print result
