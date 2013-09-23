import sys

sys.stdin = open('input.txt')
while True:
    line = raw_input().strip()
    if line == '*':
        break
    elif line[0] in set('0123456789'):
        n = int(line)
        result = []
        while n:
            result.append(chr(ord('a') + (n - 1) % 26))
            n = (n - 1) // 26
        print '%-23s%s' % (''.join(reversed(result)), line)
    else:
        result = 0
        for i, c in enumerate(line[::-1]):
            result += (26 ** i) * (ord(c) - ord('a') + 1)
        s = []
        while result:
            s.append(str(result % 1000))
            result //= 1000
        print '%-23s%s' % (line, ','.join(reversed(s)))
