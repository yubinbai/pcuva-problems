import sys

sys.stdin = open('input.txt')
while True:
    try:
        a, b = map(int, raw_input().split())
    except:
        break
    result = []
    result.append("%d/%d = %d." % (a, b, a / b))
    a = a % b * 10
    used = set()
    remain = []
    while a not in used:
        remain.append(a)
        used.add(a)
        a = a % b * 10
    i = 0
    while remain[i] != a:
        result.append("%d" % (remain[i] / b))
        i += 1
    result.append("(")
    j = i
    while i < len(remain) and i < 50:
        result.append("%d" % (remain[i] / b))
        i += 1
    if i < len(remain):
        result.append("...")
    result.append(")\n")
    result.append("   %d = number of digits in repeating cycle\n" %
                  (len(remain) - j))
    print ''.join(result)
