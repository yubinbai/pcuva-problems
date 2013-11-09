import sys

sys.stdin = open('input.txt')
n = int(input())
names = []
for _ in range(n):
    names.append(raw_input().strip())
song = 'Happy birthday to you Happy birthday to you Happy birthday to Rujia Happy birthday to you'.split(
)
last = max(n, len(song))
for i in range(last):
    print names[i % n] + ': ' + song[i % len(song)]
