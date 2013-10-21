import sys


class nStr(object):

    def __init__(self, value):
        super(nStr, self).__init__()
        self.value = value

    def __lt__(self, other):
        return self.value + other.value >= other.value + self.value

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    s = map(nStr, raw_input().strip().split())
    print ''.join([a.value for a in sorted(s)])
