import sys


sys.stdin = open('input.txt')
while True:
    try:
        num, p = raw_input().split()
    except:
        break
    p = int(p)
    index = num.find('.')
    dotPos = (5 - index) * p
    num = int(num.replace('.', ''))
    num = str(pow(num, p))
    left = num[:-1 * dotPos]
    right = num[-1 * dotPos:]
    print '%s.%s' % (left, right.strip('0'))
