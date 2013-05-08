'''
1.6.8
25
Australian Voting
PC/UVa IDs: 110108/10142, Popularity: B, Success rate: low Level: 1
'''
import collections
def getWinner(voters, n):
	for aRound in range(n):
		currentVote = []
		for voter in voters:
			currentVote.append(voter[0])
		
		result = collections.Counter(currentVote)

		#winner
		for i in result:
			if result[i] > len(voters)/2:
				return i

		#loser
		losers = set()
		minVotes = len(voters)
		for i in result:
			if result[i] < minVotes:
				minVotes = result[i]

		for i in result:
			if result[i] == minVotes:
				losers.add(i)

		for voter in voters:
			if voter[0] in losers:
				del voter[0]

if __name__ == '__main__':

	f = open('input.txt')

	numOfTests = int(f.readline())
	for i in range(numOfTests):
		n = int(f.readline())
		names = []
		for j in range(n):
			names.append(f.readline())
		numOfVoters = int(f.readline())

		voters = []
		for j in range(numOfVoters):
			voters.append([int(x) for x in f.readline().split()])

		winner = getWinner(voters, n)
		print(names[winner-1])