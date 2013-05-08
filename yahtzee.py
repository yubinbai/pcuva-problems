'''
PC/UVa IDs: 110208/10149, Popularity: C, Success rate: average Level: 3  
Verdict: Accepted  
'''
nBonus = 35
nRounds = 13

def nBits(number):
	counter = 0
	while number != 0:
		counter += 1
		number &= (number-1)

	return counter

def getBit(number, bit):
	mask = 1 << bit
	return (number & mask) ^ mask == 0

def scoring(dices, category):
	
	nDices = len(dices)
	retValue = 0

	if category < 6:
		for i in range(nDices):  
			if dices[i] == (category + 1):
				retValue += dices[i]
	elif category == 6: #chance
		retValue = sum(dices)
	elif category == 7: #three of a kind
		if any([dices[i] == dices[i+2] for i in [0,1,2]]):
			retValue = sum(dices)
	elif category == 8:
		if any([dices[i] == dices[i+3] for i in [0,1]]):
			retValue = sum(dices)
	elif category == 9: 
		if (dices[0] == dices[4]):
			retValue = 50
	elif category == 10:
	    value = [False for x in range(6)];  
	    for i in range(5): 
	        value[dices[i] - 1] = True;  
	
	    for i in range(3):
	        if value[i] and value[i + 1] and \
	        value[i + 2] and value[i + 3]:
	            retValue = 25;  
	elif category == 11:  
		if all([dices[i] == dices[i-1]+1 for i in range(1,5)]):
			retValue = 35
	elif category == 12:
	    if dices[0] == dices[1] and \
	        dices[2] == dices[4] or  \
	        dices[0] == dices[2] and \
	        dices[3] == dices[4]:
	        retValue = 40;  
	    
	return retValue

def DPsolve(dices):
	scores = [[scoring(dices[i], j) for j in range(nRounds)] \
				for i in range(nRounds)]

	nCombinations = 1 << nRounds
	nUpper = 64
	sum = [[-1 for j in range(nUpper)] for i in range(nCombinations)]
	sum[0][0] = 0
	memo = [[[0 for i in range(2)] for j in range(nUpper)] for k in range(nCombinations)]

	# 0 means no category is used, while 8191 means all are used
	for combination in range(nCombinations):
		for category in range(nRounds):

			# the category is not used
			if not getBit(combination, category):
				
				step = nBits(combination)
				#print step, category, combination
				s = scores[step][category] # use 'category' at 'step'

				#mark the category is used
				#goto next
				nextCombination = combination | (1 << category)
				
				if category < 6:
					addition = s 
				else:
					addition = 0
				
				for upper6 in range(nUpper): # update all related values
					if sum[combination][upper6] > -1: # value not empty
						if upper6+addition < nUpper-1: # remove overflow to upper6
							d = upper6+addition 
						else:
							d = nUpper-1

						if sum[nextCombination][d] < sum[combination][upper6] + s:
							# record decision
							memo[nextCombination][d][0] = category
							memo[nextCombination][d][1] = upper6
							sum[nextCombination][d] = sum[combination][upper6] + s
				

	currMax = 0
	bonus = 0
	upper = 0
	# max without bonus
	for upper6 in range(nUpper):
		if sum[nCombinations-1][upper6] > currMax:
			currMax = sum[nCombinations-1][upper6]
			upper = upper6

	# max with bonus
	total = currMax
	if sum[nCombinations-1][nUpper-1] > -1:
		bonus = nBonus
		total = sum[nCombinations-1][nUpper-1] + bonus

	if currMax < total:
		currMax = total
		upper = nUpper-1

	#build solution from last step
	lastCombination = nCombinations-1
	categories = [0 for x in range(nRounds)] 
	for i in range(nRounds-1, -1, -1):
		categories[i] = memo[lastCombination][upper][0]
		upper = memo[lastCombination][upper][1]
		lastCombination ^= (1 << categories[i])

	results = []
	for i in range(nRounds):
		for j in range(nRounds):
			if categories[j] == i:
				results.append((j, scores[j][i]))
	print(results)
	print(bonus, currMax)

if __name__ == '__main__':
	f = open('input.txt')

	numOfTests = int(f.readline())

	for i in range(numOfTests):
		dices = []
		for j in range(13):
			dices.append(sorted([int(x) for x in f.readline().split()]))
		#print(dices)
		DPsolve(dices)


