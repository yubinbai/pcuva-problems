import sys

sys.stdin = open('input.txt')
while True:
    try:
        cow, car, show = map(float, raw_input().split())
    except:
        break
    n = car + cow
    print '%.5f' % (car / n * (car - 1) / (n - 1 - show) + cow / n * car / (n - 1 - show))
