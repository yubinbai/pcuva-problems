#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <algorithm>

struct Tree
{
    int node;
    Tree *rchild;
    Tree *lchild;
};

int in[10005];
int pos[10005];
int t = 0;
int tt;
char c;
Tree node[10005];
inline Tree *NewNode()
{
    node[tt].lchild = NULL;
    node[tt].rchild = NULL;
    return &node[tt++];
}
Tree *build(int *in, int *pos, int len)
{
    if (len == 0)
        return NULL;
    int i = len - 1;
    while (pos[len - 1] != in[i])
        -- i;
    Tree *h = NewNode();
    h -> node = pos[len - 1];
    h -> lchild = build(in, pos, i);
    h -> rchild = build(in + i + 1, pos + i, len - i - 1);
    return h;
}
int mi[10005];
int min_sign[10005];
int k;
void dfs(Tree *root, int n)
{
    if (! root -> lchild && ! root -> rchild)
    {
        mi[k] = n + root -> node;
        min_sign[k] = root -> node;
        k ++;
        return;
    }
    if (root -> lchild)
        dfs(root -> lchild, n + root -> node);
    if (root -> rchild)
        dfs(root -> rchild, n + root -> node);
}
int main()
{
    while (scanf("%d%c", &in[t++], &c) != EOF)
    {
        if (c == '\n')
        {
            for (int i = 0; i < t; i ++)
                scanf("%d", &pos[i]);
            memset(mi, 0, sizeof(mi));
            memset(min_sign, 0, sizeof(min_sign));
            k = 0;
            tt = 0;
            Tree *root = build(in, pos, t);
            dfs(root, 0);
            int minn = mi[0];
            int sbb = 0;
            for (int i = 0; i < k; i ++)
            {
                if (minn > mi[i])
                {
                    minn = mi[i];
                    sbb = i;
                }
            }
            printf("%d\n", min_sign[sbb]);
            memset(in, 0, sizeof(in));
            memset(pos, 0, sizeof(pos));
            t = 0;
        }
    }
    return 0;
}