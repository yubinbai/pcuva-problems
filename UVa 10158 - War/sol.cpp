#include <stdio.h>
#include <vector>
using namespace std;

#define MAXN 10005
#define rep(i,n) for(i=0;i<(n);i++)

struct Node
{
    int parent, rank;
    vector< int > enemyList;
} nd[MAXN];

int n;

int findSet(int x)   //returns the root of node x
{
    if (nd[x].parent == x) return x;
    return nd[x].parent = findSet(nd[x].parent);
}

void setFriends(int x, int y)
{
    x = findSet(x);
    y = findSet(y);
    if (x == y) return; //already friends
    int i;
    rep(i, nd[y].enemyList.size()) if (nd[y].enemyList[i] == x)  //already enemies
    {
        printf("-1\n");
        return;
    }

    int j;
    if (nd[x].rank < nd[y].rank)  //y will be parent of x
    {
        nd[x].parent = y;
        //transfer x's enemyList to y's
        rep(i, nd[x].enemyList.size())
        {
            nd[y].enemyList.push_back(nd[x].enemyList[i]);
            //update the enemy's list - change x to y as y is the new root
            rep(j, nd[nd[x].enemyList[i]].enemyList.size())
            {
                if (nd[nd[x].enemyList[i]].enemyList[j] == x) nd[nd[x].enemyList[i]].enemyList[j] = y;
            }
        }
        nd[x].enemyList.clear();
    }
    else if (nd[x].rank > nd[y].rank)  //x will be parent of y
    {
        nd[y].parent = x;
        rep(i, nd[y].enemyList.size())
        {
            nd[x].enemyList.push_back(nd[y].enemyList[i]);
            rep(j, nd[nd[y].enemyList[i]].enemyList.size()) if (nd[nd[y].enemyList[i]].enemyList[j] == y) nd[nd[y].enemyList[i]].enemyList[j] = x;
        }
        nd[y].enemyList.clear();
    }
    else   //x & y same rank...so x will be parent of y with x's rank increasing by one
    {
        nd[y].parent = x;
        rep(i, nd[y].enemyList.size())
        {
            nd[x].enemyList.push_back(nd[y].enemyList[i]);
            rep(j, nd[nd[y].enemyList[i]].enemyList.size()) if (nd[nd[y].enemyList[i]].enemyList[j] == y) nd[nd[y].enemyList[i]].enemyList[j] = x;
        }
        nd[y].enemyList.clear();
        nd[x].rank++;
    }

}

void setEnemies(int x, int y)
{
    x = findSet(x);
    y = findSet(y);
    if (x == y)  //already friends
    {
        printf("-1\n");
        return;
    }
    int i;
    rep(i, nd[y].enemyList.size())
    {
        if (nd[y].enemyList[i] == x)  //already enemies
        {
            return;
        }
    }

    int j;
    //check if x & y both have a common enemy - that will be a contradiction
    rep(i, nd[x].enemyList.size())
    {
        rep(j, nd[y].enemyList.size())
        {
            if (nd[x].enemyList[i] == nd[y].enemyList[j])
            {
                printf("-1\n");
                return ;
            }
        }
    }

    //set all y's enemies as x's friends
    rep(i, nd[y].enemyList.size())
    {
        setFriends(x, nd[y].enemyList[i]);
    }

    //set all x's enemies as y's friends
    rep(i, nd[x].enemyList.size())
    {
        setFriends(nd[x].enemyList[i], y);
    }

    //do this as x & y's roots may have been changed
    x = findSet(x);
    y = findSet(y);

    nd[x].enemyList.push_back(y);
    nd[y].enemyList.push_back(x);
}

int main()
{
    int i;
    int c, x, y;
    while (scanf(" %d", &n) == 1)
    {
        rep(i, n) nd[i].parent = i, nd[i].rank = 0, nd[i].enemyList.clear(); //make set
        while (scanf(" %d %d %d", &c, &x, &y) == 3)
        {
            if (c == 0) break;
            if (c == 1)  //set friends
            {
                setFriends(x, y);
            }
            else if (c == 2)  //set enemies
            {
                setEnemies(x, y);
            }
            else if (c == 3)  //are friends
            {
                x = findSet(x);
                y = findSet(y);
                if (x == y) printf("1\n"); else printf("0\n");
            }
            else   //are enemies
            {
                x = findSet(x);
                y = findSet(y);
                rep(i, nd[x].enemyList.size()) if (nd[x].enemyList[i] == y)
                {
                    printf("1\n");
                    break;
                }
                if (i == nd[x].enemyList.size() ) printf("0\n");
            }
        }
        //printf("\n");
    }
    return 0;
}