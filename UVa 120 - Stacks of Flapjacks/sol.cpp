/*

Stacks of Flapjacks

Jose Ricardo Bustos Molina

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void flip(vector<int> &v, int i);

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << line << endl;
        istringstream iss(line);  //to split data of the line
        vector<int> v;
        stack<int> pila;
        int d;
        while (iss >> d) pila.push(d);
        while (!pila.empty())
        {
            v.push_back(pila.top());
            pila.pop();
        }
        //Pancake sorting
        for (int i = 0; i < v.size() - 1; ++i)
        {
            int max = v[i];
            int pmax = i;
            for (int j = i + 1; j < v.size(); ++j)
            {
                if (v[j] > max)
                {
                    max = v[j];
                    pmax = j;
                }
            }
            if (pmax == v.size() - 1) //case: 5 4 3 2 1 ... max is 5, one flip
            {
                flip(v, i + 1);
            }
            else if (pmax > i)        //case: 1 2 5 4 3 ... max is 5, double flip
            {
                flip(v, pmax + 1);
                flip(v, i + 1);
            }
        }
        cout << '0' << endl;
    }
    return 0;
}

//flip algorithm
void flip(vector<int> &v, int f)
{
    cout << f << " ";
    int cont = v.size();
    queue<int> q;
    while (cont >= f)
    {
        q.push(v.back());
        v.pop_back();
        --cont;
    }
    while (!q.empty())
    {
        v.push_back(q.front());
        q.pop();
    }
}
