import sys

vowels = ['A'] * 21 + ['U'] * 21 + ['E'] * 21 + ['O'] * 21 + ['I'] * 21
cons = 'JSBKTCLDMVNWFXGPYHQZR'
consonants = []
for c in cons:
    consonants += [c] * 5

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    N = int(input())
    vList = []
    for i in range(N // 2):
        vList.append(vowels[i])
    if N % 2:
        vList.append(vowels[N // 2 + 1])
    cList = []
    for i in range(N // 2):
        cList.append(consonants[i])
    vList.sort()
    cList.sort()
    result = []
    for i in range(N):
        if i % 2 == 0:
            result.append(vList[i // 2])
        else:
            result.append(cList[i // 2])

    print ''.join(result)
