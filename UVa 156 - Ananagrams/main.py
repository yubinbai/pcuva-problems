inFile = open('input.txt')

library = []
for line in inFile:
    if line.strip() == '#':
        wordD = {}
        for w in library:
            wList = list(w.lower())
            wList.sort()
            w1 = ''.join(wList)
            try:
                wordD[w1].append(w)
            except:
                wordD[w1] = [w]
        result = []
        for w in wordD:
            if len(wordD[w]) == 1:
                result.append(wordD[w][0])
        result.sort()
        print '\n'.join(result)
        library = []
    else:
        library.extend(line.split())
