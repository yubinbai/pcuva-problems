#include<iostream>
#include<cstdio>
using namespace std;

struct exp
{
    char c;
    struct exp *l;
    struct exp *r;
} a[10000];

int n;
string s;

struct exp *root;

struct exp *stack[10000];
int tos = 0;
struct exp *queue[10000];
char output[10000];
int head, tail;

void print(struct exp *t, int level)
{
    if (t)
    {
        print(t->l, level + 1);
        for (int i = 0; i < level; i++)printf("\t");
        printf("%c\n", t->c);
        print(t->r, level + 1);
    }
}

void bfs()
{
    head = tail = 0;
    queue[tail++] = root;
    tos = 0;
    while (head != tail)
    {
        output[tos++] = queue[head]->c;
        if (queue[head]->r)queue[tail++] = queue[head]->r;
        if (queue[head]->l)queue[tail++] = queue[head]->l;
        head++;
    }
    while (tos)printf("%c", output[--tos]);
    printf("\n");
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        tos = 0;
        n = s.size();
        for (int i = 0; i < n; i++)
        {
            a[i].c = s[i];
            if (islower(s[i]))
                a[i].l = a[i].r = NULL;
            else
            {
                a[i].l = stack[--tos];
                a[i].r = stack[--tos];
            }
            stack[tos++] = &a[i];
        }
        root = &a[n - 1];
        bfs();

    }
    return 0;
}