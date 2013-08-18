import random
import string
import sys
sys.stdout.write("100\n")
for i in range(100):
    for j in range(500):
        sys.stdout.write(random.choice(string.ascii_lowercase))
    sys.stdout.write('\n')
sys.stdout.write("0\n")
