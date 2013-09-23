#include <iostream>
#include <deque>
#include <string>
using namespace std;
int t[1000000];
struct queue
{
    void clear()
    {
        q.clear();
    }
    void push(int v)
    {
        q.push_back(v);
    }
    void pop()
    {
        q.pop_front();
    }
    int &front()
    {
        return q.front();
    }
    int &back()
    {
        return q.back();
    }
    bool empty()
    {
        return q.empty();
    }
    int size()
    {
        return q.size();
    }
    deque<int> q;
} q[1000], tq;

int main()
{
    int m = 0, T;
    while (cin >> T && T)
    {
        cout << "Scenario #" << ++m << endl;
        for (int i = 0; i < T; i++)
        {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int m;
                cin >> m;
                t[m] = i;
            }
            q[i].clear();
        }
        tq.clear();
        while (true)
        {
            char c;
            string s;
            cin >> c >> s;
            switch (c)
            {
            case 'E':
                int n;
                cin >> n;
                if (q[t[n]].empty()) tq.push(t[n]);
                q[t[n]].push(n);
                break;
            case 'D':
                cout << q[tq.front()].front() << endl;
                q[tq.front()].pop();
                if (q[tq.front()].empty()) tq.pop();
            }
            if (c == 'S') break;
        }
        cout << endl;
    }
}