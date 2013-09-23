#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi pset(500);
int _size;

void initSet(int N)
{
    for (int i = 0 ; i < N ; i++)
        pset[i] = i;
    _size = N;
}
int findSet(int i)
{
    return pset[i] == i ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
    if (!isSameSet(i, j))
    {
        pset[findSet(i)] = findSet(j);
        _size--;
    }
}
int getSize()
{
    return _size;
}

int T, S, P, x[500], y[500];
vector<pair<double, ii> > EdgeList;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        EdgeList.clear();
        scanf("%d %d", &S, &P);
        for (int i = 0 ; i < P ; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
        }

        for (int i = 0 ; i < P ; i++)
            for (int j = i + 1 ; j < P ; j++)
            {
                double dist = hypot((double)x[i] - x[j], (double)y[i] - y[j]);
                EdgeList.push_back(make_pair(dist, ii(i, j)));
            }

        sort(EdgeList.begin(), EdgeList.end());
        initSet(P);
        double D = 0.0;
        for (int i = 0 ; getSize() > S ; i++)
        {
            pair<double, ii> front = EdgeList[i];
            if (!isSameSet(front.second.first, front.second.second))
            {
                D = max(D, front.first);
                unionSet(front.second.first, front.second.second);
            }
        }

        printf("%.2lf\n", D);
    }
}