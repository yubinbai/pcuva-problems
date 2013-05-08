'''
2.8.6 Erd¨os Numbers
PC/UVa IDs: 110206/10044, Popularity: B, Success rate: low Level: 2
'''

import re

if __name__ == '__main__':
	s = 'Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factors'
	exp = re.compile('[A-Z][a-z]{0,100}, [A-Z]\.[A-Z]?\.?')
	#exp = re.compile('[A-Z](a-z){0,10}, [A-Z]\.')
	result = exp.findall(s)
	print(result)