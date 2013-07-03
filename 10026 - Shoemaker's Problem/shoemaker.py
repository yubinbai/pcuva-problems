'''
4.6.5 Shoemaker’s Problem
PC/UVa IDs: 110405/10026, Popularity: C, Success rate: average Level: 2
'''


class job:

    def __init__(self, id, duration, fineRate):
        self.id = id
        self.duration = duration
        self.fineRate = fineRate

    def __lt__(self, other):
        return self.duration * other.fineRate < other.duration * self.fineRate

    def __repr__(self):
        return str(self.id)

if __name__ == '__main__':
    f = open('input.txt')
    numOfTests = int(f.readline())
    f.readline()
    jobs = []
    for i in range(numOfTests):
        datasize = int(f.readline())
        for j in range(datasize):
            aJob = [int(x) for x in f.readline().split()]
            jobs.append(job(1 + j, aJob[0], aJob[1]))
    print(' '.join([str(e) for e in sorted(jobs)]))
