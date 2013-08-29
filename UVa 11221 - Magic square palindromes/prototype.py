import re
from math import sqrt

l = re.findall('\w', 'muse sun, eve.s e(y)es even use sum.')
aLen = len(l)
print ''.join(l)
side = int(sqrt(aLen))
for i in range(side):
    print ''.join(l[i * side:i * side + side])
