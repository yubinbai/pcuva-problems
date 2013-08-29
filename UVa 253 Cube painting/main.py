import sys

sys.stdin = open('input.txt')
direction = [
    [0, 1, 2, 3, 4, 5], [1, 5, 2, 3, 0, 4],
    [2, 1, 5, 0, 4, 3], [3, 1, 0, 5, 4, 2],
    [4, 0, 2, 3, 5, 1], [5, 4, 2, 3, 1, 0]]

while True:
    try:
        line = raw_input().strip()
    except:
        break
    origin = line[:6]
    new = line[6:]
    temp = [0] * 6
    flag = False
    for i in range(6):
        for j in range(6):
            temp[j] = new[direction[i][j]]
        for r in range(4):
            char = temp[1]
            temp[1] = temp[2]
            temp[2] = temp[4]
            temp[4] = temp[3]
            temp[3] = char
            if ''.join(temp) == origin:
                flag = True
                break
        if flag:
            break
    if flag:
        print 'TRUE'
    else:
        print 'FALSE'
