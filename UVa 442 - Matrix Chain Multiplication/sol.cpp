#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct tuple
{
    int f;
    int s;
    tuple(): f(-1), s(-1) {}
    tuple(int _f, int _s)
    {
        f = _f;
        s = _s;
    }
    int first()
    {
        return f;
    }
    int second()
    {
        return s;
    }
};

queue<char> eval(string &s);
bool isLetter(char c);

int m[26][2];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        cin >> m[c - 65][0];
        cin >> m[c - 65][1];
    }
    string s;
    cin.get();
    while (getline(cin, s))
    {
        queue<char> q = eval(s);
        stack<tuple> p;
        bool error = false;
        long count = 0;
        while (!q.empty() && !error)
        {
            char c = q.front();
            if (isLetter(c))
            {
                p.push( tuple(m[c - 65][0], m[c - 65][1]) );
            }
            else
            {
                tuple t2 = p.top();
                p.pop();
                if (!p.empty())
                {
                    tuple t1 = p.top();
                    p.pop();
                    if (t1.second() == t2.first())
                    {
                        tuple newt = tuple(t1.first(), t2.second());
                        count += t1.first() * t1.second() * t2.second();
                        p.push(newt);
                    }
                    else
                    {
                        error = true;
                        break;
                    }
                }
                else
                {
                    p.push(t2);
                }
            }
            q.pop();
        }
        if (error) cout << "error" << endl;
        else cout << count << endl;
    }
}

queue<char> eval(string &s)
{
    stack<char> p;
    queue<char> q;
    char prev = '\0';
    for (string::iterator it = s.begin(); it < s.end(); ++it)
    {
        char c = *it;
        //Operator * invisible
        if (isLetter(prev) && isLetter(c) ||
                isLetter(prev) && c == '(' ||
                prev == ')' && isLetter(c) ||
                prev == ')' && c == '(')
        {
            if (!(p.empty() || p.top() == '('))
            {
                while (!p.empty() && p.top() != '(') //i don't consider the relevance
                {
                    char aux = p.top();
                    p.pop();
                    q.push(aux);
                }
            }
            p.push('*'); //push operator
        }

        if (isLetter(c))
        {
            q.push(c);
        }
        else if (c == '(')
        {
            p.push('(');
        }
        else if (c == ')')
        {
            while (!p.empty() && p.top() != '(')
            {
                char aux = p.top();
                p.pop();
                q.push(aux);
            }
            if (!p.empty()) p.pop();
        }
        prev = c;
    }
    while (!p.empty())
    {
        char aux = p.top();
        p.pop();
        q.push(aux);
    }
    return q;
}

bool isLetter(char c)
{
    return c >= 'A' && c <= 'Z';
}