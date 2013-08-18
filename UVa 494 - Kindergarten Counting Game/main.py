import re

inFile = open('input.txt')
for line in inFile:
    row = re.findall('[a-zA-Z]+', line)
    print(len(row))
