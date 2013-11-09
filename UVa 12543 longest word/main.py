import re
import sys

sys.stdin = open('input.txt')
s = []
while True:
    try:
        s.append(raw_input().strip())
        s.append(' ')
    except:
        break
s = ''.join(s)
maxW, m = '', 0
for w in re.split('[^a-zA-Z\-]', s):
    if len(w) > m:
        maxW, m = w, len(w)
print maxW.lower()
