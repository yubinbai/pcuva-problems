import sys

sys.stdin = open('input.txt')
while True:
    try:
        N = int(input())
    except:
        break
    songs = []
    for i in range(N):
        sID, sLen, sFreq = map(float, raw_input().split())
        songs.append((sFreq / sLen, sID))
    songs.sort()
    # print songs
    M = int(input())
    print int(songs[M - 1][1])
