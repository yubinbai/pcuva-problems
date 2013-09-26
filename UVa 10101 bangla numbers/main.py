import sys


def tran(n):
    d1 = n % 100
    n //= 100
    d2 = n % 10
    n //= 10
    d3 = n % 100
    n //= 100
    d4 = n % 100
    n //= 100
    if n > 100:
        result = tran(n)
        result.append('kuti')
    else:
        result = []
    if d4:
        result.append(str(d4))
        result.append('lakh')
    if d3:
        result.append(str(d3))
        result.append('hajar')
    if d2:
        result.append(str(d2))
        result.append('shata')
    if d1:
        result.append(str(d1))
    return result


sys.stdin = open('input.txt')
itertest = 0
while True:
    try:
        n = int(input())
    except:
        break
    itertest += 1
    print '%4d. %s' % (itertest, ' '.join(tran(n)))
