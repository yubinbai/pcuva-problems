import sys
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])


class Line:

    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

    def __str__(self):
        return '%s %s' % (str(self.p1), str(self.p2))


def turn(p, q, r):
    '''
    application of cross product
    '''
    x1, y1 = q.x - p.x, q.y - p.y  # vector p->q
    x2, y2 = r.x - q.x, r.y - q.y  # vector q->r

    result = x1 * y2 - x2 * y1  # 1 cross 2
    if result < 0:
        return 1  # P->Q->R is a right turn
    if result > 0:
        return -1  # P->Q->R is a left turn
    return 0  # P->Q->R is a straight Line, i.e. P, Q, R are collinear


def ccw(p, q, r):
    return int(turn(p, q, r) > 0)


def intersect(line1, line2):
    return ((ccw(line1.p1, line1.p2, line2.p1) * ccw(line1.p1, line1.p2, line2.p2)) <= 0) \
        and \
        ((ccw(line2.p1, line2.p2, line1.p1) * ccw(line2.p1, line2.p2, line1.p2)) <= 0)

if __name__ == '__main__':
    sys.stdin = open('input.txt')
    numTest = int(input())
    for itertest in range(numTest):
        row = map(int, raw_input().split())
        p1 = Point(row[0], row[1])
        p2 = Point(row[2], row[3])
        line = Line(p1, p2)

        left, top, right, bottom = row[4:]
        p1 = Point(left, top)
        p2 = Point(right, top)
        p3 = Point(left, bottom)
        p4 = Point(right, bottom)
        edges = [Line(p1, p2), Line(p1, p3), Line(p3, p4), Line(p2, p4)]

        inter = False
        for e in edges:
            if intersect(e, line):
                print e
                print line
                inter = True
                break
        if inter:
            print('T')
        else:
            print('F')
