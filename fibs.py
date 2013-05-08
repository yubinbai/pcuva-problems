'''
6.6.1 How Many Fibs?
PC/UVa IDs: 110601/10183, Popularity: B, Success rate: average Level: 1
'''

def getFibs(size, result):
	result.add(1)
	currFib = 1
	nextFib = 1
	while nextFib < size:
		currFib, nextFib = nextFib, currFib+nextFib
		result.add(nextFib)

def count(result, start, end):
	counter = 0
	for i in result:
		if i >= start and i <= end:
			counter += 1
	return counter

if __name__ == '__main__':
	result = set()
	getFibs(10**100, result)
	f = open('input.txt')
	while True:
		start, end = [int(x) for x in f.readline().split()]
		if start == 0:
			break
		print(count(result, start, end))