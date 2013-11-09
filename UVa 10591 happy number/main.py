from bitstring import BitArray
import sys

sys.stdin = open('input.txt')
MAXN = 1000000005
isHappy = BitArray(MAXN)
unHappy = BitArray(MAXN)
isHappy[1] = True

for case in range(1, 1 + int(input())):
    try:
        n = int(input())
    except:
        break
    path = set()
    curr = n
    flag = True
    while not isHappy[curr] and not unHappy[curr]:
        if isHappy[curr]:
            break
        if unHappy[curr]:
            flag = False
            break
        path.add(curr)
        curr = sum(map(lambda x: x ** 2, map(int, str(curr))))
        if curr in path:
            flag = False
            break
    if flag:
        isHappy.set(True, path)
        print 'Case #%d: %d is a Happy number.' % (case, n)
    else:
        unHappy.set(True, path)
        print 'Case #%d: %d is an Unhappy number.' % (case, n)
