import sys

sys.stdin = open('input.txt')
while True:
    try:
        line = raw_input().strip()
    except:
        break
    if ord(line[0]) in range(ord('0'), ord('9') + 1):
        result = []
        line = line[::-1]
        for i in range(len(line) // 2):
            result.append(chr(int(line[2 * i:2 * i + 2])))
        print ''.join(result)
    else:
        result = []
        for c in line:
            result.append(str(ord(c)))
        result = ''.join(result)
        result = result[::-1]
        print result
