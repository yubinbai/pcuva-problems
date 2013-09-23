#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str1[100005], str2[100005];

class Node
{
public:
    char data;
    Node *son[4];
};
Node node[20000];
int nIndex, pos1, pos2, sum;
inline Node *NewNode()
{
    node[nIndex].data = 0;
    for (int i = 0; i < 4; ++i) node[nIndex].son[i] = NULL;
    return &node[nIndex++];
}
// 通过序列建树
Node *BuildTree(Node *root, int &pos, char *str)
{
    ++pos;
    if ( pos == strlen(str) ) return NULL;
    root = NewNode();
    root->data = str[pos];
    if (str[pos] == 'p')
    {
        for (int i = 0; i < 4; ++i)
        {
            if (root->son[i] == NULL)
            {
                root->son[i] = BuildTree(root->son[i], pos, str);
            }
        }
    }
    return root;
}
// 用深搜遍历两棵树求出合并后的黑色像素个数
void dfs(Node *root1, Node *root2, int level)
{
    if (!root1 && !root2) return ;

    if (!root1)
    {
        if (root2->data == 'f')
        {
            sum += 1024 >> (level * 2);
            return;
        }
        for (int i = 0; i < 4; ++i)
            dfs(root1, root2->son[i], level + 1);
        return;
    }
    if (!root2)
    {
        if (root1->data == 'f')
        {
            sum += 1024 >> (level * 2);
            return;
        }
        for (int i = 0; i < 4; ++i)
            dfs(root1->son[i], root2, level + 1);
        return;
    }
    if (root1->data == 'f' || root2->data == 'f')
    {
        sum += 1024 >> (level * 2);
        return ;
    }

    for (int i = 0; i < 4; ++i)
        dfs(root1->son[i], root2->son[i], level + 1);
}

void output(Node *root)
{
    if (root)
    {
        printf("%c", root->data);
        for (int i = 0; i < 4; ++i)
            output(root->son[i]);
    }
}

void Solve()
{
    Node *root1 = NULL, *root2 = NULL;
    pos1 = -1, pos2 = -1;
    nIndex = 0;
    root1 = BuildTree(root1, pos1, str1);
    root2 = BuildTree(root2, pos2, str2);
    sum = 0;
    dfs(root1, root2 , 0);
    printf("There are %d black pixels.\n", sum);
}

int main()
{
    int T;
    scanf("%d%*c", &T);
    while (T--)
    {
        scanf("%s %s", str1, str2);
        Solve();
    }
    return 0;
}