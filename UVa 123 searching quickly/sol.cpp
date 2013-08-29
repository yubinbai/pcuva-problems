#include<iostream>
#include<cstdio>
#include "string.h"
#include "stdlib.h"
using namespace std;

char t[1000];
char *words[50];
int n = 0;
char *titles[200];
int m = 0;
struct kwic
{
    char *word;
    char *title;
    int seq;
};
struct kwic kwics[3000];
int l = 0;

void lowercase(char *s)
{
    while (*s)
    {
        *s = tolower(*s);
        s++;
    }
}

int wordcmp(char **p, char **q)
{
    return strcmp(*p, *q);
}

int kwiccmp(struct kwic *p, struct kwic *q)
{
    if (int d = strcmp(p->word, q->word))return d;
    return p->seq - q->seq;
}

int main()
{
    while (gets(t) && strcmp(t, "::") != 0)
    {
        if (strcmp(t, "") == 0)continue;
        lowercase(t);
        words[n++] = strdup(t);
    }
    while (gets(t))
    {
        if (strcmp(t, "") == 0)continue;
        lowercase(t);
        titles[m++] = strdup(t);
    }
    qsort(words, n, sizeof(char *), (int( *)(const void *, const void *))wordcmp);
    for (int i = 0; i < m; i++)
    {
        strcpy(t, titles[i]);
        for (char *tok = strtok(t, " "); tok; tok = strtok(NULL, " "))
        {
            if (!bsearch(&tok, words, n, sizeof(char *),
                         (int( *)(const void *, const void *))wordcmp))
            {
                kwics[l].word = strdup(tok);
                kwics[l].title = strdup(titles[i]);
                for (char *c = kwics[l].title + (tok - t); *c && *c != ' '; c++)
                    *c = toupper(*c);
                kwics[l].seq = l;
                l++;
            }
        }
    }
    qsort(kwics, l, sizeof(struct kwic), (int( *)(const void *, const void *))kwiccmp);
    for (int i = 0; i < l; i++)puts(kwics[i].title);
    return 0;
}