import sys

sys.stdin = open('input.txt')
while True:
    try:
        x, y = map(int, raw_input().split())
    except:
        break
    result = [x // y]
    x -= (x // y) * y
    while y > 1:
        result.append(y // x)
        x, y = (y - y // x * x), x
    print '[%d; %s]' % (result[0], ', '.join(str(i) for i in result[1:]))
