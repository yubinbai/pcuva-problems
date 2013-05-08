'''
6.6.6 The Priest Mathematician
PC/UVa IDs: 110606/10254, Popularity: C, Success rate: high Level: 2
'''
def hanoi3(disks, memo3):
	if memo3[disks] != -1:
		return memo3[disks]
	if disks == 0:
		memo3[disks] = 0
		return 0
	memo3[disks] = 2*hanoi3(disks-1, memo3) + 1
	return memo3[disks]


def hanoi4(disks, memo3, memo4):
	if memo4[disks] != -1:
		return memo4[disks]
	currMin = hanoi3(disks, memo3)
	for k in range(1, disks):
		s = 2*hanoi4(k, memo3, memo4) + hanoi3(disks-k, memo3)
		if s < currMin:
			currMin = s
	memo4[disks] = currMin
	return currMin

if __name__ == '__main__':
	f = open('input.txt')
	while True:
		line = f.readline()
		if line == '':
			break
		disks = int(line)
		memo3 = [-1 for x in range(disks+1)]
		memo4 = [-1 for x in range(disks+1)]
		print(hanoi4(disks, memo3, memo4))
		