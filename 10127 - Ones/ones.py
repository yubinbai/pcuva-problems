'''
5.9.4 Ones
PC/UVa IDs: 110504/10127, Popularity: A, Success rate: high Level: 2
'''


def Ones(number):
    counter = 0
    while number != 0:
        if number % 10 != 1:
            return -1
        counter += 1
        number //= 10
    return counter

if __name__ == '__main__':
    f = open('input.txt')

    for line in f:
        if line == '':
            break
        number = int(line)
        multiplier = 1
        ones = -1
        while True:
            ones = Ones(number * multiplier)
            if ones != -1:
                break
            multiplier += 1
        print(ones)
