import sys

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip().split()
    except:
        break
    if line[1] == '/':
        print int(line[0]) / int(line[2])
    else:
        print int(line[0]) % int(line[2])
