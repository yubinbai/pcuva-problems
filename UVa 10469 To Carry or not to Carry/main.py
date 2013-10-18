import sys

sys.stdin = open('input.txt')
while True:
    try:
        a, b = map(int, raw_input().split())
    except:
        break
    print a ^ b
