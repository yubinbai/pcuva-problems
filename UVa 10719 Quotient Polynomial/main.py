# b_n-1 * (-k) + b_n-2 = a_n-1
# b_n-1 = an
import sys

sys.stdin = open('input.txt')
while True:
    try:
        k = int(input())
    except:
        break
    a = map(int, raw_input().split())
    b = [a[0]]
    for i in a[1:]:
        b.append(i - b[-1] * (-1 * k))
    print b[:-1]
    print b[-1]
