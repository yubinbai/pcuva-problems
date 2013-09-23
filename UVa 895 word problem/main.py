import sys


def subsets(seq):
    def _subsets(step):
        results.append(list(path))
        for i in range(step, len(seq)):
            if i != step and seq[i] == seq[i - 1]:
                continue
            path.append(seq[i])
            _subsets(i + 1)
            path.pop()
    seq = list(seq)
    seq.sort()
    results = []
    path = []
    _subsets(0)
    return results


sys.stdin = open('input.txt')
d = {}
while True:
    w = raw_input().strip()
    if w == '#':
        break
    w1 = ''.join(sorted(list(w)))
    try:
        d[w1] += 1
    except:
        d[w1] = 1
while True:
    w = raw_input().strip().split()
    if w[0] == '#':
        break
    total = 0
    for comb in subsets(w):
        w1 = ''.join(sorted(comb))
        try:
            total += d[w1]
        except:
            continue
    print total
