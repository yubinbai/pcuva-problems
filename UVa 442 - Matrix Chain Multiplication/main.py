import sys


def evaluate(exp):
    if len(exp) == 1:
        A = exp[0]
        return 0, mat[A][0], mat[A][1]
    if exp[0] == '(':
        depth = 1
        pos = 1
        while pos < len(exp):
            if exp[pos] == '(':
                depth += 1
            elif exp[pos] == ')':
                depth -= 1
            if depth == 0:
                break
            pos += 1
        if pos == len(exp) - 1:
            return evaluate(exp[1:-1])
        else:
            cost1, r1, c1 = evaluate(exp[1:pos])
            cost2, r2, c2 = evaluate(exp[pos + 1:])
    else:
        cost1, r1, c1 = evaluate(exp[:1])
        cost2, r2, c2 = evaluate(exp[1:])
    if c1 != r2 or cost1 == -1 or cost2 == -1:
        return -1, 0, 0
    else:
        return cost1 + cost2 + r1 * c1 * c2, r1, c2


sys.stdin = open('input.txt')
N = int(input())
mat = {}
for i in range(N):
    line = raw_input().strip().split()
    mat[line[0]] = (int(line[1]), int(line[2]))
while True:
    try:
        exp = list(raw_input().strip())
    except:
        break
    cost, row, col = evaluate(exp)
    if cost == -1:
        print 'error'
    else:
        print cost
