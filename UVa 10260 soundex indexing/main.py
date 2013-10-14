import sys

sys.stdin = open('input.txt')
chars = map(set, ['', 'BFPV', 'CGJKQSXZ', 'DT', 'L', 'MN', 'R'])
while True:
    try:
        s = raw_input()
    except:
        break
    ids = []
    for c in s:
        for i, cSet in enumerate(chars):
            if c in cSet:
                ids.append(i)
                break
        else:
            ids.append(-1)
    result = [None]
    for i in ids:
        if i != result[-1]:
            result.append(i)
    print ''.join(map(str, filter(lambda x: x != -1, result[1:])))
