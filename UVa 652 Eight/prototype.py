from itertools import permutations

num = list(range(9))
path = {}

for p in permutations(num):
    path[p] = 'path' + str(p)

# test for running time
for p in permutations(num):
    if path[p] != 'path' + str(p):
        print 'False'

#[Finished in 1.7s]
