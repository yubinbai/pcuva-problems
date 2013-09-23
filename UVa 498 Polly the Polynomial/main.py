import sys

sys.stdin = open('input.txt')
while True:
    try:
        coef = map(int, raw_input().split())
        x = map(int, raw_input().split())
    except:
        break
    coef.reverse()
    for x1 in x:
        print sum(c * (x1 ** i) for i, c in enumerate(coef)),
    print
