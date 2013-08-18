from itertools import product, combinations
import re
import sys


def judge(role, p, s, it):
    if s[1] == 'It':
        return (s[-1] == it)
    if s[1] == 'I':
        currP = p
    else:
        currP = person[s[1]]

    if s[3] == 'not':
        if s[-1] == 'lying':
            return role[currP] == 'divine' or (it == 'day' and role[currP] == 'human')
        else:
            return role[currP] != s[-1]
    else:
        if s[-1] == 'lying':
            return role[currP] == 'evil' or (it == 'night' and role[currP] == 'human')
        else:
            return role[currP] == s[-1]


sys.stdin = open('input.txt')
person = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4}
while True:
    N = int(input())
    if N == 0:
        break
    statements = []
    for i in range(N):
        line = raw_input().strip()
        statements.append(re.findall('\w+', line))

    solution = []

    for role in product(['divine', 'human', 'evil'], repeat=5):
        for it in ['day', 'night']:
            valid = True
            for s in statements:
                p = person[s[0]]
                if role[p] == 'evil' or (role[p] == 'human' and it == 'night'):
                    valid = not judge(role, p, s, it)
                else:
                    valid = judge(role, p, s, it)
                if not valid:
                    break
            if valid:
                s = list(role)
                s.append(it)
                solution.append(list(s))
    '''
    处理方法就是将所有情况列举出来，然后将语句进行判断。如果出现两组满足，就将两组中相同的保留（这些是可以确定的）

    注意：即使没有人类被确定，但是白天黑夜已经被分出来了，也要输出。
    '''
    if solution:
        result = list(solution[0])
        for s in solution[1:]:
            for i in range(6):
                if s[i] != result[i] and result[i] != None:
                    result[i] = None
        print result
    else:
        print 'Not possible'
