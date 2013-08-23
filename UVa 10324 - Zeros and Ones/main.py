from numpypy import *
import sys


class FenwickTree:

    '''
    // In this implementation, the tree is represented by a list
    // Elements are numbered by 0, 1, ..., n-1.
    // tree[i] is sum of elements with indexes i&(i+1)..i, inclusive.
    // (Note: this is a bit different from what is proposed in Fenwick's article.
    // To see why it makes sense, think about the trailing 1's in binary
    // representation of indexes.)
    '''

    def __init__(self, size, initValue=0):
        self.tree = empty((size), dtype=int)
        self.tree.fill(initValue)

    def increase(self, i, delta):
        '''
         Increases value of i-th element by ''delta''.
        '''
        while i < len(self.tree):
            self.tree[i] += delta
            i |= i + 1

    def getsum(self, left, right):
        '''
        left and right need to be non-negative
        Returns sum of elements with indexes left..right, inclusive; (zero-based);
        '''
        if left == 0:
            return self._sum(right)
        return self._sum(right) - self._sum(left - 1)

    def _sum(self, index):
        currSum = 0
        while index >= 0:
            currSum += self.tree[index]
            index &= index + 1
            index -= 1
        return currSum

sys.stdin = open('input.txt')
itertest = 1
while True:
    try:
        line = raw_input().strip()
    except:
        break
    tree = FenwickTree(len(line))
    for i, c in enumerate(line):
        if c == '1':
            tree.increase(i, 1)
    print 'Case %d:' % itertest
    itertest += 1
    for q in range(int(input())):
        i, j = map(int, raw_input().split())
        if i > j:
            i, j = j, i
        s = tree.getsum(i, j)
        # print i, j, s,
        if s == 0 or s == j - i + 1:
            print 'Yes'
        else:
            print 'No'
