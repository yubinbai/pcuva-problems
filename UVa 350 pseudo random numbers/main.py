import sys

sys.stdin = open('input.txt')
case = 0
while True:
    z, i, m, l = map(int, raw_input().split())
    if not any([z, i, m, l]):
        break
    case += 1
    used = [0] * m
    counter = 1
    while not used[l]:
        used[l] = counter
        l = (z * l + i) % m
        counter += 1
    print 'Case %d: %d' % (case, counter - used[l])
