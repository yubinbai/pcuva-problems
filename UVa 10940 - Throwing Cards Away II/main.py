from collections import *

for i in range(3, 200):
    q = deque(list(range(1, i + 1)))
    a, b = 0, 0
    # print q
    while True:
        a = q.popleft()
        if q:
            b = q.popleft()
        else:
            break
        q.append(b)
    j = 1
    while j < i:
        j <<= 1
    print 'i:%d \t%d\t%d' % (i, a, (i - j // 2) * 2)
