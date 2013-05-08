'''
2.8.2
43
Poker Hands
PC/UVa IDs: 110202/10315, Popularity: C, Success rate: average Level: 2
'''

class Card:
	suit = ''
	value = ''
	def __init__(self, string):
		self.suit = string[1]
		self.value = string[0]
	def __lt__(self, other):
		return self.rank() < other.rank()
	def __eq__(self, other):
		return self.rank() == other.rank()
	def rank(self):
		numbers = [str(x) for x in range(2, 10)]
		if self.value in numbers:
			return int(self.value)
		elif self.value == 'T':
			return 10
		elif self.value == 'J':
			return 11
		elif self.value == 'Q':
			return 12
		elif self.value == 'K':
			return 13
		elif self.value == 'A':
			return 14

class Hand:
	cards = []
	rank = 0
	def __init__(self, string):
		self.cards = [Card(x) for x in string]

		#get rank
		# high card, pair, two pair, three of a kind, straight, flush, full house,
		# four of a kind, straight flush
		# 0, 1, 2, 3, 4, 5, 6, 7, 8
		if self.isStraightFlush():
			self.rank = 8
		elif self.isFourOfaKind():
			self.rank = 7
		elif self.isFullHouse():
			self.rank = 6
		elif self.isFlush():
			self.rank = 5
		elif self.isStraight():
			self.rank = 4
		elif self.isThreeOfaKind():
			self.rank = 3
		elif self.isTwoPair():
			self.rnak = 2
		elif self.isPair():
			self.rank = 1
		else:
			self.rank = 0

	def __lt__(self, other):
		if self.rank > other.rank:
			return 1
		elif self.rank < other.rank:
			return -1
		else:
			for i in range(4,-1,-1):
				equal = self.cards[i].__eq__(other.cards[i])
				if not equal:
					break
			return self.cards[i].__lt__(other.cards[i])
	def isStraightFlush(self):
		return self.isFlush() and self.isStraight()
	def isFourOfaKind(self):
		if all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(0, 3)]):
			self.swapCards(0,4)
			return True
		elif all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(1, 4)]):
			return True
		else:
			return False
	def isFullHouse(self):
		if all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(0, 2)]) \
				and self.cards[3].rank() == self.cards[4].rank():
			self.swapCards(0,4)
			self.swapCards(1,3)
			return True
		elif all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(2, 4)]) \
				and self.cards[0].rank() == self.cards[1].rank():
			return True
		else:
			return False
	def isFlush(self):
		for card in self.cards:
			if card.suit !=  self.cards[0].suit:
				return False
		return True
	def isStraight(self):
		for i in range(1, 5):
			if self.cards[i].rank() != self.cards[i-1].rank():
				return False
		return True
	def isThreeOfaKind(self):
		if all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(0, 2)]) \
				or all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(1, 3)]) \
				or all([self.cards[i].rank() == self.cards[i+1].rank() for i in range(2, 4)]):
			return True
		else:
			return False
	def isTwoPair(self):
		if all([self.cards[i].rank() == self.cards[i+1].rank() for i in [0,2]]) \
				or all([self.cards[i].rank() == self.cards[i+1].rank() for i in [0,3]]) \
				or all([self.cards[i].rank() == self.cards[i+1].rank() for i in [1,3]]):
			return True
		else:
			return False
	def isPair(self):
		if any([self.cards[i].rank() == self.cards[i+1].rank() for i in range(4)]):
			return True
		else:
			return False


if __name__ == '__main__':

	f = open('input.txt')

	while True:
		line = f.readline()
		if line == '':
			break
		hand1 = Hand(line[0:14].split())
		hand2 = Hand(line[15:].split())
		if hand2 < hand1:
			print('Black wins.')
		elif hand1 < hand2:
			print('White wins.')
		else:
			print('Tie')