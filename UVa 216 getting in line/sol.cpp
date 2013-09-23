#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <cfloat>


using namespace std;


struct node
{
    double x;
    double y;
    node(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double d(node *n)
    {
        return sqrt((x - (n->x)) * (x - (n->x)) + (y - (n->y)) * (y - (n->y)));
    }
};


void TSP(queue<int> &q, double **ds, stack<int> &path, vector<node *> &ns, vector<int> &pathmin, double dp, double &min);


int main()
{
    ostringstream oss;
    int t = 1, N;
    cin >> N;
    oss.precision(2);
    oss.setf(ios::fixed, ios::floatfield);
    if (N != 0) oss << "**********************************************************" << endl;
    while (N != 0)
    {
        oss << "Network #" << t++ << endl;
        vector<node *> ns;
        for (int i = 0; i < N; ++i)
        {
            double x, y;
            cin >> x >> y;
            ns.push_back(new node(x, y));
        }
        queue<int> q;
        double **ds = new double*[N];
        for (int i = 0; i < N; ++i)
        {
            q.push(i);
            ds[i] = new double[N];
            fill(ds[i], ds[i] + N, 0.0);
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                ds[i][j] = ns[i]->d(ns[j]) + 16;
                ds[j][i] = ds[i][j];
            }
        }
        stack<int> path;
        vector<int> pathmin(ns.size());
        double min = DBL_MAX;
        TSP(q, ds, path, ns, pathmin, 0, min);
        for (vector<int>::iterator it = pathmin.end() - 2; it >= pathmin.begin(); --it)
        {
            node *a = ns[*(it + 1)];
            node *b = ns[*it];
            oss << "Cable requirement to connect (" << int(a->x) << "," << int(a->y);
            oss << ") to (";
            oss << int(b->x) << "," << int(b->y) << ") is " << ds[*(it + 1)][*it] << " feet." << endl;
        }
        oss << "Number of feet of cable required is " << min <<  "." << endl;
        cin >> N;
        if (N != 0) oss << "**********************************************************" << endl;
    }
    cout << oss.str();
}


void TSP(queue<int> &q, double **ds, stack<int> &path, vector<node *> &ns, vector<int> &pathmin, double dp, double &min)
{
    if (q.empty())
    {
        if (dp < min)
        {
            min = dp;
            int i = 0;
            while (!path.empty())
            {
                pathmin[i++] = path.top();
                path.pop();
            }
            for (vector<int>::iterator it = pathmin.end() - 1; it >= pathmin.begin(); --it) path.push(*it);
        }
        return;
    }
    for (int i = 0; i < q.size(); ++i)
    {
        int id = q.front();
        q.pop();
        double d = 0;
        if (!path.empty())
        {
            int ant = path.top();
            d += ds[id][ant];
        }
        path.push(id);
        TSP(q, ds, path, ns, pathmin, dp + d, min);
        path.pop();
        q.push(id);
    }
}
