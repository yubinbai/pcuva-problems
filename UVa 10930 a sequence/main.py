import sys

sys.stdin = open('input.txt')
while True:
    try:
        a = map(int, raw_input().strip().split())
    except:
        break
    print a[1:]
    s = set([a[1] + a[2]])
    flag = True
    for i in range(3, len(a)):
        if a[i] in s:
            flag = False
        else:
            s2 = set(a[i] + e for e in s)
            for j in range(1, i):
                s2.add(a[i] + a[j])
            s = s.union(s2)
    if flag:
        print 'This is an A-sequence.'
    else:
        print 'This is not an A-sequence.'
