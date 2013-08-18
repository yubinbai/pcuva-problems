'''
Australian Voting
PC/UVa IDs: 110108/10142, Popularity: B, Success rate: low Level: 1
'''
import collections


def getWinner(voters, n):
    # loser
    losers = set()
    currentVotes = [0] * (n + 1)
    for aRound in range(n):
        for voter in voters:
            if aRound == 0 or voter[aRound - 1] in losers:
                currentVotes[voter[aRound]] += 1
        # get max and min votes
        currMax, maxP = -1, []
        currMin, minP = n, []
        for i in range(1, n + 1):
            if i not in losers:
                if currentVotes[i] >= currMax:
                    if currentVotes[i] == currMax:
                        maxP.append(i)
                    else:
                        currMax, maxP = currentVotes[i], [i]
                elif currentVotes[i] <= currMin:
                    if currentVotes[i] == currMin:
                        minP.append(i)
                    else:
                        currMin, minP = currentVotes[i], [i]
        if currMax > n // 2 + 1:
            return maxP
        if currMin == currMax:
            return maxP
        for p in minP:
            losers.add(p)

if __name__ == '__main__':

    f = open('input.txt')

    numOfTests = int(f.readline())
    f.readline()
    for i in range(numOfTests):
        n = int(f.readline())
        names = []
        for j in range(n):
            names.append(f.readline().strip())

        voters = []
        while True:
            line = f.readline()
            if line == '':
                break
            voters.append([int(x) for x in line.split()])

        winners = getWinner(voters, n)
        print('\n'.join(names[e - 1] for e in winners))
