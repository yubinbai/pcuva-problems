#!/usr/bin/env python
# -*- coding: utf-8 -*-

# tri des caractères utilisés dans une chaîne


def simple_kark_sort(s):
    n = len(s)
    s += (unichr(1) * 3)
    SA = [0 for _ in s]
    alpha = sorted(set(s))
    kark_sort(s, SA, n, alpha)
    return SA


def kark_sort(s, SA, n, alpha):
    n0 = (n + 2) / 3
    n1 = (n + 1) / 3
    n2 = n / 3
    n02 = n0 + n2
    SA12 = [0] * (n02 + 3)
    SA0 = [0] * n0
    s12 = []

# begin modification (from : htmllist)##
#  max = n + n0 - n1
#  for i in range(max) :
#    if i % 3 != 0:
#      s12.append(i)
    s12 = [i for i in xrange(n + n0 - n1) if i % 3 != 0]
# end moditication

    s12.extend([0, 0, 0])
#  s_2 = s[2:]

#  sx = iter(s)
#  sx.next().next()
    radixpass(s12, SA12, s[2:], n02, alpha)
    radixpass(SA12, s12, s[1:], n02, alpha)
    radixpass(s12, SA12, s, n02, alpha)

    name = 0
    c0, c1, c2 = -1, -1, -1
    array_name = [0]
    for i in xrange(n02):
        if s[SA12[i]] != c0 or s[SA12[i] + 1] != c1 or s[SA12[i] + 2] != c2:
            name += 1
            array_name.append(name)
            c0 = s[SA12[i]]
            c1 = s[SA12[i] + 1]
            c2 = s[SA12[i] + 2]
        if SA12[i] % 3 == 1:
            s12[SA12[i] / 3] = name
        else:
            s12[SA12[i] / 3 + n0] = name

    if name < n02:
        kark_sort(s12, SA12, n02, array_name)
        for i in xrange(n02):
            s12[SA12[i]] = i + 1
    else:
        for i in xrange(n02):
            SA12[s12[i] - 1] = i

    s0 = [SA12[i] * 3 for i in xrange(n02) if SA12[i] < n0]

    radixpass(s0, SA0, s, n0, alpha)

    p = j = k = 0
    t = n0 - n1
    while k < n:
        i = SA12[t] * 3 + 1 if SA12[t] < n0 else (SA12[t] - n0) * 3 + 2

#    j = p < n0 and SA0[p] or 0
        j = SA0[p] if p < n0 else 0

        if SA12[t] < n0:
            test = (s12[SA12[t] + n0] <= s12[j / 3]) if(
                s[i] == s[j]) else (s[i] < s[j])
        elif(s[i] == s[j]):
            test = s12[SA12[t] - n0 + 1] <= s12[j / 3 + n0] if(
                s[i + 1] == s[j + 1]) else s[i + 1] < s[j + 1]
        else:
            test = s[i] < s[j]

        if(test):
            SA[k] = i
            t += 1
            if t == n02:
                k += 1
                l = n0 - p
#        SA[k:k+l] = SA0[p:n0]
#        p = n0
#        k += l
                while p < n0:
                    SA[k] = SA0[p]
                    p += 1
                    k += 1

        else:
            SA[k] = j
            p += 1
            if p == n0:
                k += 1
                while t < n02:
                    SA[k] = (SA12[t] * 3) + 1 if SA12[
                        t] < n0 else ((SA12[t] - n0) * 3) + 2
                    t += 1
                    k += 1
        k += 1


def radixpass(a, b, r, n, k):
    c = {}
    for lettre in k:
        c[lettre] = 0

    for i in xrange(n):
        c[r[a[i]]] += 1

    somme = 0
    for lettre in k:
        freq, c[lettre] = c[lettre], somme
        somme += freq

    for i in xrange(n):
        b[c[r[a[i]]]] = a[i]
        c[r[a[i]]] += 1

    return b


def LCP(s, suffix_array):
    n = len(s)
    rank = [0 for i in xrange(n)]
    LCP = [0 for i in xrange(n)]
    for i in xrange(n):
        rank[suffix_array[i]] = i
    l = 0
    for j in xrange(n):
        l = max(0, l - 1)
        i = rank[j]
        j2 = suffix_array[i - 1]
        if i:
            while l + j < n and l + j2 < n and s[j + l] == s[j2 + l]:
                l += 1
            LCP[i - 1] = l
#      LCP[i-1] = (i-1, l, max(j + l, j2 + l))
        else:
            l = 0
    return LCP


if (__name__ == '__main__'):
    print "tools.py"
