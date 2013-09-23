import sys

deck = [0]
num = ["2", "3", "4", "5", "6", "7",
       "8", "9", "10", "Jack", "Queen", "King", "Ace"]
color = ["Clubs", "Diamonds", "Hearts", "Spades"]
hand = list(range(53))
for c in color:
    for i in num:
        deck.append(i + ' of ' + c)
sys.stdin = open('input.txt')
numTest = int(input())
raw_input()
for itertest in range(numTest):
    S = int(input())
    shuffles = []
    for x in range(S):
        s = [0]
        while len(s) < 52:
            s += map(int, raw_input().split())
        shuffles.append(list(s))
    while True:
        try:
            line = raw_input().strip()
        except:
            break
        if len(line) == 0:
            break
        n = int(line)
        hand = [hand[shuffles[n - 1][i]] for i in range(53)]
    for i in hand[1:]:
        print deck[i]
