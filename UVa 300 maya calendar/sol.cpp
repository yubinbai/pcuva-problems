#include <stdio.h>
#include <string.h>
char haab[20][10] =
{
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};
char tzolkin[20][10] =
{
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};
int main()
{
    int n, i, day, year;
    unsigned totaldays, findyears, extradays, extramonths, number;
    char month[15];
    scanf("%d", &n);
    printf("%d\n", n);
    for (; n; n--)
    {
        scanf("%d. %s %d", &day, month, &year);
        totaldays = year * 365;
        for (i = 0; i < 19; i++)
            if (strcmp(haab[i], month) == 0)
                break;
        totaldays += (i * 20 + day + 1);
        findyears = (totaldays - 1) / 260;
        extradays = totaldays - findyears * 260;
        extramonths = (extradays - 1) % 20;
        number = (extradays - 1) % 13;
        printf("%d ", ++number);
        printf("%s ", tzolkin[extramonths]);
        printf("%d\n", findyears);
    }
    return 0;
}