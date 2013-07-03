'''
Created on 2013-6-25

@author: Administrator
'''
import unittest

def scramble(s):
    sList = s.split()
    tList = []
    for e in sList:
        tList.append(e[::-1])
    return ' '.join(tList)

class Test(unittest.TestCase):

    def testScrable(self):
        l1 = ['I love you.', 'You love me.', 'We\'re a happy family.']
        l2 = ['I evol .uoy', 'uoY evol .em', 'er\'eW a yppah .ylimaf']
        for k, v in zip(l1, l2): 
            self.assertEqual(v, scramble(k))

if __name__ == "__main__":
    # import sys;sys.argv = ['', 'Test.testScrable']
    unittest.main()
