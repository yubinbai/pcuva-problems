import sys
import itertools

monH = dict(
    zip(['pop', 'no', 'zip', 'zotz', 'tzec', 'xul', 'yoxkin', 'mol', 'chen',
         'yax', 'zac', 'ceh', 'mac', 'kankin', 'muan', 'pax', 'koyab', 'cumhu'], range(19)))
nameT = [
    'imix', 'ik', 'akbal', 'kan', 'chicchan', 'cimi', 'manik', 'lamat', 'muluk',
    'ok', 'chuen', 'eb', 'ben', 'ix', 'mem', 'cib', 'caban', 'eznab', 'canac', 'ahau']
sys.stdin = open('input.txt')
cases = int(input())
print cases
for _ in range(cases):
    d, m, y = raw_input().strip().split()
    d = int(d.strip('.'))
    m = monH[m]
    y = int(y)
    nDays = y * 365 + m * 20 + d
    y = nDays / (20 * 13)
    d = nDays % (20 * 13)
    print d % 13 + 1, nameT[d % 20], y
