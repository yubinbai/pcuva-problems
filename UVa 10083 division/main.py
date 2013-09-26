import sys
import math

sys.stdin = open('input.txt')
while True:
    try:
        t, a, b = map(int, raw_input().split())
    except:
        break
    print "(%d^%d-1)/(%d^%d-1)" % (t, a, t, b),
    if t == 1:
        print("is not an integer with less than 100 digits.")
        continue
    if a == b:
        print 1
        continue
    if a % b != 0 or a < b:
        print("is not an integer with less than 100 digits.")
        continue
    if (a - b) * math.log10(t) > 99:
        print("is not an integer with less than 100 digits.")
        continue
    X = pow(t, a) - 1
    Y = pow(t, b) - 1
    if Y == 0:
        print("is not an integer with less than 100 digits.")
        continue
    tmp = X % Y
    X = X / Y
    print(X)
