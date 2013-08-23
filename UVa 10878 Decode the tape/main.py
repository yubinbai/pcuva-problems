import sys

sys.stdin = open('input.txt')
raw_input()
result = []
while True:
    line = raw_input().strip()
    if line == '___________':
        break
    binStr = line.replace(' ', '0').replace(
        'o', '1').strip('|').replace('.', '')
    # print binStr
    n = int(binStr, base=2)
    result.append(chr(n))
print ''.join(result)
