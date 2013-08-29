import sys


class Point(object):

    def __init__(self, x, y):
        super(Point, self).__init__()
        self.x = x
        self.y = y

    def __lt__(self, other):
        if (fabs(x - other.x) > EPS):
            return x < other.x
        return y < other.y


class Vector(object):

    def __init__(self, _x, _y):
        self.x = _x
        self.y = _y


def toVector(p1, p2):
    return Vector(p2.x - p1.x, p2.y - p1.y)


def rot90(v1):
    return Vector(v1.y, -1.0 * v1.x)

sys.stdin = open('input.txt')
while True:
    try:
        x1, y1, x2, y2 = map(float, raw_input().split())
    except:
        break
    mid = Point((x1 + x2) / 2, (y1 + y2) / 2)
    p1 = Point(x1, y1)
    p2 = Point(x2, y2)
    v1 = toVector(mid, p1)
    v2 = toVector(mid, p2)
    l1 = rot90(v1)
    l2 = rot90(v2)
    print l1.x + mid.x, l1.y + mid.y, l2.x + mid.x, l2.y + mid.y
