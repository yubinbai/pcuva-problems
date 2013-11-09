import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
    except:
        break
    count = 0
    p = 1
    while p < n:
        if (count & 1):
            p <<= 1
        else:
            p += (p << 3)
        count += 1
    if count & 1:
        print 'Stan wins.'
    else:
        print 'Ollie wins.'
