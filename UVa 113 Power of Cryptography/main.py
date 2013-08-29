import sys

sys.stdin = open('input.txt')
while True:
    try:
        n = int(input())
        p = int(input())
    except:
        break
    low, high = 1, (1 << 30)
    while low <= high:
        mid = (low + high) >> 1
        v = pow(mid, n)
        if v > p:
            high = mid - 1
        elif v < p:
            low = mid + 1
        else:
            break
    print mid

