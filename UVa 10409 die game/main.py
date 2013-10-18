import sys

sys.stdin = open('input.txt')
while True:
    n = int(input())
    if not n:
        break
    top = 1
    bottom = 6
    east = 4
    west = 3
    north = 2
    south = 5
    for _ in range(n):
        cmd = raw_input().strip()
        if cmd == "north":
            top, bottom, south, north = south, north, bottom, top
        elif cmd == "south":
            top, bottom, south, north = north, south, top, bottom
        elif cmd == "east":
            top, bottom, west, east = west, east, top, bottom
        elif cmd == "west":
            top, bottom, east, west = east, west, bottom, top
    print top
