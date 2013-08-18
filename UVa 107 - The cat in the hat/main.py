# 1. get power roots
# 2. trial for n
# 3. plug n into equation
import sys
sys.stdin = open('input.txt')
EPSILON = 1e-12

while True:
    A, B = map(int, raw_input().split())
    if A == 0:
        break
    if A == 1:
        print 0, 1
        continue
    for i in range(2, 100):
        a, b = pow(A, 1.0 / i), pow(B, 1.0 / i)
        intA = int(round(a))
        intB = int(round(b))
        if b <= 2:
            break
        if abs(a - intA) < EPSILON and abs(b - intB) < EPSILON\
                and intA == intB + 1:
            # print intA, intB
            r1, r2 = (1 - b ** i) / (1 - b), \
                A * (1 - (b / a) ** i) / (1 - (b / a)) + B
            print int(r1), int(r2)
            # break
