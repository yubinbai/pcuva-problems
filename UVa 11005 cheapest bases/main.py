import sys

sys.stdin = open('input.txt')
for case in range(1, int(input()) + 1):
    cost = []
    for _ in range(4):
        cost += map(int, raw_input().split())

    def key(base):
        x = n
        num = []
        while x:
            num.append(x % base)
            x //= base
        return sum(cost[i] for i in num)
    print 'Case %d:' % case
    for _ in range(int(input())):
        n = int(input())
        res = []
        for e in sorted(range(2, 37), key=key):
            if not res or key(e) == key(res[-1]):
                res.append(e)
        print 'Cheapest base(s) for number %d: %s' % (n, ' '.join(map(str, res)))
