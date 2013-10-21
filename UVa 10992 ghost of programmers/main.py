import sys

sys.stdin = open('input.txt')
ghost = [('Tanveer Ahsan', 2),
         ('Shahriar Manzoor', 5),
         ('Adrian Kugel', 7),
         ('Anton Maydell', 11),
         ('Derek Kisman', 15),
         ('Rezaul Alam in', 20),
         ('Jimmy Mardell', 28),
         ('Monirul Hasan', 36)]
while True:
    n = int(input())
    if not n:
        break
    print n
    flag = False
    for name, v in ghost:
        if n >= 2148 and n % v == 2148 % v:
            print 'Ghost of %s' % name
            flag = True
    if n >= 2148 and (n % 400 == 0 or (n % 4 == 0 and n % 100 != 0)):
        print 'Ghost of K. M. Iftekhar'
        flag = True
    if not flag:
        print 'No ghost will come in this year'
    print
