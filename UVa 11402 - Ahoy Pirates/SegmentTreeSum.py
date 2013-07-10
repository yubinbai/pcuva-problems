'''
Created on Jun 18, 2013

@author: Yubin Bai

Segment Tree Library
The segment tree is stored like a heap array
'''
import unittest

class SegmentTreeSum:
    
    def __init__(self, N):
        self.length = 1
        while self.length < 2 * N:
            self.length <<= 1
        self.tree = [0] * self.length
        
    def buildTree(self, A, node, b, e):
        self.A = list(A)
        def _build(node, b, e):
            if b == e:
                self.tree[node] = A[b]
            else:
                left = 2 * node
                right = 2 * node + 1
                _build(left, b, (b + e) // 2)
                _build(right, (b + e) // 2 + 1, e)
                lContent = self.tree[left]
                rContent = self.tree[right]
                self.tree[node] = lContent + rContent
        _build(1, 0, len(A) - 1)
        
    def query(self, start, end):
        '''
        find sum in interval [i, j]
        '''
        end = min(end, len(self.A) - 1)
        start = max(0, start)
        
        def _query(node, b, e):
            if start > e or end < b:
                return 0
            if b >= start and e <= end:
                return self.tree[node]
            v1 = _query(2 * node, b, (b + e) // 2)
            v2 = _query(2 * node + 1, (b + e) // 2 + 1, e)
            return v1 + v2
        return _query(1, 0, len(self.A) - 1)
        
    def update(self, pos, value):
        '''
        update A[pos] to a new value
        '''
        increment = value - self.A[pos]
        self.A[pos] = value
        def _update(node, p, b, e):
            if p < b or p > e:
                return
            if b == e:
                self.tree[node] += increment
                return
            self.tree[node] += increment 
            _update(node * 2, p, b, (b + e) // 2)
            _update(node * 2 + 1, p, (b + e) // 2 + 1, e)
        _update(1, pos, 0, len(self.A) - 1)
        
class Test(unittest.TestCase):

    def testSum(self):
        A = [8, 7, 3, 9, 5, 1, 10]
        t = SegmentTreeSum(len(A))
        t.buildTree(A, 1, 0, 6)
        self.assertEqual(sum(t.A[1:4]), t.query(1, 3))
        self.assertEqual(sum(t.A), t.query(0, 6))

        t.update(3, 2)
        self.assertEqual(sum(t.A[1:4]), t.query(1, 3))
        t.update(2, 1)
        self.assertEqual(sum(t.A[1:4]), t.query(1, 3))

if __name__ == "__main__":
    # import sys;sys.argv = ['', 'Test.testInit']
    unittest.main()
