'''
3.8.3 Common Permutation
PC/UVa IDs: 110303/10252, Popularity: A, Success rate: average
'''
import collections


def commonPermutation(s1, s2):
    c1 = collections.Counter(s1)
    c2 = collections.Counter(s2)

    p = {}
    for i in c1:
        if i in c2:
            if c1[i] < c2[i]:
                p[i] = c1[i]
            else:
                p[i] = c2[i]

    result = []
    for i in p:
        result.append(i * p[i])
    result.sort()
    return ''.join(result)

if __name__ == '__main__':
    f = open('input.txt')

    for line in f:
        if line == '':
            break
        s1 = line.strip()
        s2 = f.readline().strip()
        print(commonPermutation(s1, s2))
