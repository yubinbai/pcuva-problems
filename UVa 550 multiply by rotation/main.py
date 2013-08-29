import sys

sys.stdin = open('input.txt')
while True:
    try:
        base, d, f = map(int, raw_input().split())
    except:
        break
    d0 = d
    counter = 1
    carry = 0
    while True:
        d1 = d * f + carry
        carry, d = divmod(d1, base)
        if carry == 0 and d == d0:
            break
        else:
            counter += 1
    print counter
