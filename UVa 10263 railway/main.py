from math import *
import sys

INF = 1e9
EPS = 1e-9
PI = acos(-1.0)


class Point(object):

    """docstring for Point"""

    def __init__(self, x, y):
        super(Point, self).__init__()
        self.x = x
        self.y = y

    def __lt__(self, other):
        if (fabs(x - other.x) > EPS):
            return x < other.x
        return y < other.y


def dist(p1, p2):
    return hypot(p1.x - p2.x, p1.y - p2.y)


class Line(object):

    def __init__(self):
        self.a = self.b = self.c = None


def pointsToLine(p1, p2, line):
    if (fabs(p1.x - p2.x) < EPS):
        line.a = 1.0
        line.b = 0.0
        line.c = -1 * p1.x
    else:
        line.a = -(doublinee)(p1.y - p2.y) / (p1.x - p2.x)
        line.b = 1.0
        line.c = -(doublinee)(line.a * p1.x) - p1.y


class Vector(object):

    """docstring for Vector"""

    def __init__(self, _x, _y):
        self.x = _x
        self.y = _y


def toVector(p1, p2):
    return Vector(p2.x - p1.x, p2.y - p1.y)


def scaleVector(v, s):
    return Vector(v.x * s, v.y * s)


def translate(p, v):
    return Point(p.x + v.x, p.y + v.y)


def dot(a, b):
    return (a.x * b.x + a.y * b.y)


def norm_sq(v):
    return v.x ** 2 + v.y ** 2


def distToLine(p, A, B):
    Ap = toVector(A, p)
    AB = toVector(A, B)
    u = dot(Ap, AB) / norm_sq(AB)
    c = translate(A, scaleVector(AB, u))
    return dist(p, c), c


def distToLineSegment(p, A, B):
    Ap = toVector(A, p)
    AB = toVector(A, B)
    u = dot(Ap, AB) / norm_sq(AB)
    if (u < 0.0):
        return dist(p, A), Point(A.x, A.y)
    if (u > 1.0):
        return dist(p, B), Point(B.x, B.y)
    return distToLine(p, A, B)

if __name__ == '__main__':

    sys.stdin = open('input.txt')
    rails = [None] * 10010

    while True:
        try:
            x = float(input())
        except:
            break
        y = float(input())
        n = int(input())
        m = Point(x, y)

        for i in range(n + 1):
            rails[i] = Point(float(input()), float(input()))

        ans, ansP = min(distToLineSegment(m, rails[i], rails[i + 1])
                        for i in range(n))
        print "%.4lf\n%.4lf\n" % (ansP.x, ansP.y)
