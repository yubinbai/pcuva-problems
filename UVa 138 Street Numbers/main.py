counter = 10
sums = 1
k = 2
currLast = 1
while counter > 0:
    k += 1
    while sums < (k + 1) ** 2:
        currLast += 1
        sums += currLast

    if sums == (k + 1) ** 2:
        counter -= 1
        print (k + 1), currLast
