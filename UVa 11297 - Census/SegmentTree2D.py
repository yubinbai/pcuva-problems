from math import log
import unittest
import random


class Rect(object):

    """Rectangle for 2d segment tree"""

    def __init__(self, y1, x1, y2, x2):
        self.y1 = y1
        self.x1 = x1
        self.y2 = y2
        self.x2 = x2

    def isCell(self):
        return self.y1 == self.y2 and self.x1 == self.x2

    def contains(self, other):
        return other.x1 >= self.x1 and other.x2 <= self.x2 \
            and other.y1 >= self.y1 and other.y2 <= self.y2 \
            and self.overlap(other)

    def overlap(self, other):
        return self.x1 <= other.x2 and self.x2 >= other.x1 \
            and self.y1 <= other.y2 and self.y2 >= other.y1

    def rect0(self):
        ymid = (self.y1 + self.y2) >> 1
        xmid = (self.x1 + self.x2) >> 1
        return Rect(self.y1, self.x1, ymid, xmid)

    def rect1(self):
        ymid = (self.y1 + self.y2) >> 1
        xmid = (self.x1 + self.x2) >> 1
        return Rect(self.y1, xmid + 1, ymid, self.x2)

    def rect2(self):
        ymid = (self.y1 + self.y2) >> 1
        xmid = (self.x1 + self.x2) >> 1
        return Rect(ymid + 1, self.x1, self.y2, xmid)

    def rect3(self):
        ymid = (self.y1 + self.y2) >> 1
        xmid = (self.x1 + self.x2) >> 1
        return Rect(ymid + 1, xmid + 1, self.y2, self.x2)

    def __str__(self):
        return ' '.join(str(e) for e in [self.y1, self.x1, self.y2, self.x2])

    def __eq__(self, other):
        return self.y1 == other.y1 and self.x1 == other.x1 and\
            self.y2 == other.y2 and self.x2 == other.x2


class SegmentTree2D(object):

    """SegmentTree2D"""

    def buildTree(self, mat, func, padding=0):
        '''
        build segment tree from a matrix
        '''
        def _buildTree(mat, length):
            '''
            build a layer of matrix, length l, on top of matrix
            '''
            mat2 = []
            for i in range(length):
                row = []
                for j in range(length):
                    v1 = mat[i << 1][j << 1]
                    v2 = mat[(i << 1) + 1][j << 1]
                    v3 = mat[i << 1][(j << 1) + 1]
                    v4 = mat[(i << 1) + 1][(j << 1) + 1]
                    row.append(func(v1, v2, v3, v4))
                mat2.append(row)
            return mat2

        self.func = func
        N = len(mat)
        M = len(mat[0])
        self.length = 1
        while self.length < max(N, M):
            self.length <<= 1

        tree = []
        length = self.length
        tree.append([])
        for i in range(length):
            tree[0].append([padding] * length)
        for i in range(N):
            for j in range(M):
                tree[0][i][j] = mat[i][j]

        while length > 1:
            length >>= 1
            tree.append(_buildTree(tree[-1], length))
        self.tree = tree

    def query(self, y1, x1, y2, x2):
        '''
        query the segment tree for value
        '''
        def _query(layer, rectCurr, rectQ):
            '''
            query the layer
            '''
            if layer < 0:
                raise 'Error layer'

            if rectQ.contains(rectCurr):
                return self.tree[layer][rectCurr.y1 >> layer][rectCurr.x1 >> layer]

            values = []

            r1 = rectCurr.rect0()
            if r1.overlap(rectQ):
                values.append(_query(layer - 1, r1, rectQ))
            r1 = rectCurr.rect1()
            if r1.overlap(rectQ):
                values.append(_query(layer - 1, r1, rectQ))
            r1 = rectCurr.rect2()
            if r1.overlap(rectQ):
                values.append(_query(layer - 1, r1, rectQ))
            r1 = rectCurr.rect3()
            if r1.overlap(rectQ):
                values.append(_query(layer - 1, r1, rectQ))
            return self.func(*values)

        rectQ = Rect(y1, x1, y2, x2)
        rectMax = Rect(0, 0, self.length - 1, self.length - 1)
        return _query(len(self.tree) - 1, rectMax, rectQ)

    def update(self, y1, x1, value):
        '''
        update cell with value
        '''
        self.tree[0][y1][x1] = value
        for layer in range(1, len(self.tree)):
            y1 >>= 1
            x1 >>= 1
            v1 = self.tree[layer - 1][y1 << 1][x1 << 1]
            v2 = self.tree[layer - 1][(y1 << 1) + 1][x1 << 1]
            v3 = self.tree[layer - 1][y1 << 1][(x1 << 1) + 1]
            v4 = self.tree[layer - 1][(y1 << 1) + 1][(x1 << 1) + 1]
            self.tree[layer][y1][x1] = self.func(v1, v2, v3, v4)


class Test(unittest.TestCase):

    def testMax(self):

        def maxFunc(*args):
            return max(args)

        mat = []
        size = 4
        for i in range(size):
            row = []
            for j in range(size):
                row.append(random.randrange(2000))
            mat.append(row)

        treeMax = SegmentTree2D()
        treeMax.buildTree(mat, maxFunc)
        y1, x1, y2, x2 = 0, 0, 1, 1
        v1 = treeMax.query(y1, x1, y2, x2)
        m1 = 0
        for i in range(y1, y2 + 1):
            for j in range(x1, x2 + 1):
                m1 = max(m1, mat[i][j])
        self.assertEquals(v1, m1)

        y1, x1, y2, x2 = 1, 2, 2, 2
        v1 = treeMax.query(y1, x1, y2, x2)
        m1 = 0
        for i in range(y1, y2 + 1):
            for j in range(x1, x2 + 1):
                m1 = max(m1, mat[i][j])
        self.assertEquals(v1, m1)


if __name__ == "__main__":
    # import sys;sys.argv = ['', 'Test.testInit']
    unittest.main()
