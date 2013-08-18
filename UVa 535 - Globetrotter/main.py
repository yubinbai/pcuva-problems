from math import acos, sin, cos
PI = 3.141592653589793
R = 6378.0


def dist(c1, c2):
    x1, y1 = c1[0] / 180.0 * PI, c1[1] / 180.0 * PI
    x2, y2 = c2[0] / 180.0 * PI, c2[1] / 180.0 * PI
    return R * acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(y1 - y2))

inFile = open('input.txt')
cities = {}
while True:
    line = inFile.readline().strip()
    if line == '#':
        break
    row = line.split()
    cities[row[0]] = (float(row[1]), float(row[2]))
while True:
    line = inFile.readline().strip()
    if line == '# #':
        break
    query = line.strip().split()
    try:
        d = dist(cities[query[0]], cities[query[1]])
        print '%s - %s' % (query[0], query[1])
        print '%d km' % round(d)
    except:
        print '%s - %s' % (query[0], query[1])
        print 'Unknown'
