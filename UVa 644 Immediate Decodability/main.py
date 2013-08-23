import sys
from itertools import combinations

sys.stdin = open('input.txt')
codes = []
while True:
    try:
        line = raw_input().strip()
    except:
        break
    if line == '9':
        flag = True
        for w1, w2 in combinations(codes, 2):
            prefix = []
            i = min(len(w1), len(w2)) - 1
            while i >= 0:
                if w1[i] != w2[i]:
                    break
                else:
                    i -= 1
            prefix = ''.join(prefix)
            if i == -1:
                flag = False
                break
        if flag:
            print 'immediately decodable'
        else:
            print 'not immediately decodable'
        # print codes
        codes = []
    else:
        codes.append(line)
