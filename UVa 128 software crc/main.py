import sys

sys.stdin = open('input.txt')
while True:
    line = raw_input().strip()
    if line == '#':
        break
    result = 0
    for c in line:
        result = ((result << 8) + ord(c)) % 34943
    result = (result << 16) % 34943
    result = 34943 - result
    r1 = (result & 0xFF)
    r2 = (result & 0xFF00) >> 8
    # print hex(r2 | 0x100).upper()[-2:], hex(r1 | 0x100).upper()[-2:]
    print('%02X %02X' % (r2, r1))
