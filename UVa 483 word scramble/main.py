'''
Created on 2013-6-25

@author: Yubin Bai
'''


def scramble(s):
    sList = s.split()
    tList = []
    for e in sList:
        tList.append(e[::-1])
    return ' '.join(tList)


f = open('input.txt')
for line in f:
    print(scramble(line.strip()))
