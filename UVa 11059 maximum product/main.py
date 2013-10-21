import sys
import operator

sys.stdin = open('input.txt')
case = 0
while True:
    try:
        n = int(input())
        a = map(int, raw_input().split())
    except:
        break
    try:
        raw_input()
    except:
        pass
    result = 0
    case += 1
    for i in range(n - 1):
        for j in range(i + 1, n + 1):
            result = max(result, reduce(operator.mul, a[i:j]))
    print 'Case #%d: The maximum product is %d.\n' % (case, result)
