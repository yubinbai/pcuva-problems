import sys

sys.stdin = open('input.txt')
while True:
    try:
        b1, b2, n = raw_input().split()
    except:
        break
    try:
        number = int(n, base=int(b1))
        number2 = int(str(number), base=int(b2))
        print '%s base %s = %d base %s' % (n, b1, number2, b2)
    except:
        print '%s is an illegal base %s number' % (n, b1)
