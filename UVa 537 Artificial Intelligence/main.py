import sys
import re

sys.stdin = open('input.txt')
numTest = int(input())
for itertest in range(numTest):
    line = raw_input().strip()
    P = re.findall('P=[0-9.]+[mKM]*W', line)
    U = re.findall('U=[0-9.]+[mKM]*V', line)
    I = re.findall('I=[0-9.]+[mKM]*A', line)
    if P:
        p = float(P[0].strip('mKMP=W'))
        if P[0][-2] == 'm':
            p *= 1e-3
        elif P[0][-2] == 'M':
            p *= 1e6
        elif P[0][-2] == 'M':
            p *= 1e3
    if U:
        u = float(U[0].strip('mKMU=V'))
        if U[0][-2] == 'm':
            u *= 1e-3
        elif U[0][-2] == 'M':
            u *= 1e6
        elif U[0][-2] == 'M':
            u *= 1e3
    if I:
        i = float(I[0].strip('mKMI=A'))
        if I[0][-2] == 'm':
            i *= 1e-3
        elif I[0][-2] == 'M':
            i *= 1e6
        elif I[0][-2] == 'M':
            i *= 1e3
    if P and U:
        print 'I=%.2fA' % (p / u)
    elif P and I:
        print 'U=%.2fV' % (p / i)
    elif U and I:
        print 'P=%.2fW' % (u * i)
