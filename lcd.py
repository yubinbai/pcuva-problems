'''
1.6.4
LCD Display
PC/UVa IDs: 110104/706, Popularity: A, Success rate: average Level: 1
'''

def makeLine(size, digit, i):
	if i == 0:
		# top position
		if digit in [0, 2, 3, 5, 6, 7, 8, 9]:
			return ' ' + ''.join(['-' for x in range(size)]) + ' '
		else:
			return ''.join([' ' for x in range(size+2)])
	elif i <= size:
		# two bars
		if digit in [0, 4, 8, 9]:
			return '|' + ''.join([' ' for x in range(size)]) + '|'
		elif digit in [1, 2, 3, 7]:
			return ' ' + ''.join([' ' for x in range(size)]) + '|'
		else:
			return '|' + ''.join([' ' for x in range(size)]) + ' '
	elif i == size+1:
		# middle
		if digit in [2, 3, 4, 5, 6, 8 ,9]:
			return ' ' + ''.join(['-' for x in range(size)]) + ' '
		else:
			return ''.join([' ' for x in range(size+2)])
	elif i <= 2*size+1:
		# two bars
		if digit in [0, 6, 8]:
			return '|' + ''.join([' ' for x in range(size)]) + '|'
		elif digit in [1, 3, 4, 5, 7, 9]:
			return ' ' + ''.join([' ' for x in range(size)]) + '|'
		else:
			return '|' + ''.join([' ' for x in range(size)]) + ' '
	else:
		#bottom
		if digit in [0, 2, 3, 5, 6, 8]:
			return ' ' + ''.join(['-' for x in range(size)]) + ' '
		else:
			return ''.join([' ' for x in range(size+2)])

def addDigit(output, size, digit):
	for i in range(2*size+3):
		line = makeLine(size, digit, i)
		output[i] += list(line)

if __name__ == '__main__':

	f = open('input.txt')

	numOfTests = int(f.readline())
	for i in range(numOfTests):
		size, number = [int(x) for x in f.readline().split()]

		results = [[] for x in range(2*size+3)]

		s = list(str(number))

		for digit in s:
			addDigit(results, size, int(digit))
		
		for x in range(2*size+3):
			print ''.join(results[x])

