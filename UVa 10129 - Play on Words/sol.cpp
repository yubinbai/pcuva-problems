#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int adj[26][26];
int E;
int In[26];
int Out[26];
int stack[30];
int set[26];
int tos;
void stackInit()
{
    memset(set, 0, sizeof(set));
    tos = 0;
}
void push(int u)
{
    if (set[u])return;
    set[u]++;
    stack[tos++] = u;
}
int pop()
{
    int u = stack[--tos];
    set[u]--;
    return u;
}
bool stackEmpty()
{
    if (tos)return false;
    else return true;
}
void addEdge(int u, int v)
{
    adj[u][v]++;
    In[v]++;
    Out[u]++;
}
void removeEdge(int u, int v)
{
    adj[u][v]--;
    In[v]--;
    Out[u]--;
}
void graphInit()
{
    memset(adj, 0, sizeof(adj));
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
}
void printGraph()
{
    for (int i = 0; i < 26; i++)
    {
        cout << (char)('A' + i) << ": ";
        for (int j = 0; j < 26; j++)
            if (adj[i][j])cout << (char)('A' + j) << adj[i][j] << " ";
        cout << endl;
    }
}
bool graphEmpty()
{
    int sum = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            sum += adj[i][j];
    if (sum)return false;
    else return true;
}
void eulerR(int u)
{
    if (!Out[u])return;
    int v;
    for (int i = 0; i < 26; i++)
    {
        v = i;
        if (adj[u][v])
        {
            push(v);
            removeEdge(u, v);
            break;
        }
    }
    eulerR(v);
}
bool checkEulerPath()
{
    int no_of_start = 0;
    int no_of_end = 0;
    int start = 0;
    int end = 0;
    for (int i = 0; i < 26; i++)
    {
        if (In[i] > Out[i] + 1 || In[i] + 1 < Out[i])return false;
        if (In[i] == Out[i] + 1)
        {
            no_of_end++;
            end = i;
        }
        if (In[i] + 1 == Out[i])
        {
            no_of_start++;
            start = i;
        }
    }
    if (no_of_start == 1 && no_of_end == 1 || no_of_start == 0 && no_of_end == 0)
    {
        stackInit();
        push(start);
        while (!stackEmpty())
        {
            int u = pop();
            eulerR(u);
        }
    }
    else
        return false;
    //  printGraph();
    if (graphEmpty())return true;
    else return false;
}
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        graphInit();
        cin >> E;
        string s;
        for (int j = 0; j < E; j++)
        {
            cin >> s;
            int u = s[0] - 'a';
            int v = s[s.size() - 1] - 'a';
            addEdge(u, v);
        }
        if (checkEulerPath())
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;
        //debug();
    }
    return 0;
}
