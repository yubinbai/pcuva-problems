import sys

sys.stdin = open('input.txt')

# type 'simplify (x-a)/(x-a+y-a), a = (x+y)/3' into wolfram alpha
for _ in range(int(input())):
    x, y, a = map(int, raw_input().split())
    print a * (2 * x - y) / (x + y)
