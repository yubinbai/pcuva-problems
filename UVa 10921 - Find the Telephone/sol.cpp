#include <stdio.h>
int main()
{
    char map[127];
    register char c;
    map['0'] = '0';
    map['1'] = '1';
    map['A'] = map['B'] = map['C'] = '2';
    map['D'] = map['E'] = map['F'] = '3';
    map['G'] = map['H'] = map['I'] = '4';
    map['J'] = map['K'] = map['L'] = '5';
    map['M'] = map['N'] = map['O'] = '6';
    map['P'] = map['Q'] = map['R'] = map['S'] = '7';
    map['T'] = map['U'] = map['V'] = '8';
    map['W'] = map['X'] = map['Y'] = map['Z'] = '9';
    map['\n'] = '\n';
    map['-'] = '-';
    while ((c = getchar()) != EOF)
        putchar(map[c]);
    return 0;
}