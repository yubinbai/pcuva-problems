#include <iostream>
#include <string>

using namespace std;

struct statement
{
    char a;
    char b;
    bool c;
    char d;
} p[50];

void get(statement &t)
{
    char c;
    cin >> c;
    t.a = c - 'A';
    cin >> c >> c;
    if (c == 'I')
    {
        cin.get(c);
        if (c == 't') t.b = 5; else t.b = t.a;
    }
    else t.b = c - 'A';
    string s;
    cin >> s >> s;
    if (s == "not") t.c = true, cin >> s; else t.c = false;
    switch (s[0])
    {
    case 'd': t.d = 0; break;
    case 'e': t.d = 2; break;
    case 'l': t.d = 3; break;
    default: t.d = 1;
    }
}

bool lying(short state, char who)
{
    return (state >> who + who & 3) + (state >> 10 & 1) >= 2;
}

bool check(statement st, short s)
{
    return (st.d == 3 ? lying(s, st.b) : st.d == (s >> st.b + st.b & 3)) ^ st.c ^ lying(s, st.a);
}

bool checks(short s)
{
    for (int i = 0; i < 5; ++i)
        if ((s >> i + i & 3) == 3)
            return false;
    return true;
}

void combine(short &a, short b)
{
    for (int i = 0; i < 6; ++i)
        if (a & (3 << i + i) ^ b & (3 << i + i))
            a |= (3 << i + i);
}

const char *s[] = { "divine", "human", "evil" };

int main()
{
    int n, t = 0;
    while (cin >> n && n)
    {
        cout << "Conversation #" << ++t << endl;
        short a = -1;
        for (int i = 0; i < n; ++i) get(p[i]);
        for (int i = 0; i < 0x800; ++i) if (checks(i))
            {
                bool b = true;
                for (int j = 0; j < n; ++j) if (!check(p[j], i))
                    {
                        b = false;
                        break;
                    }
                if (!b) continue;
                if (a == -1) a = i; else combine(a, i);
            }
        if (a == -1) cout << "This is impossible." << endl;
        if (a == 0xFFF) cout << "No facts are deducible." << endl;
        for (int i = 0; i < 5; ++i)
        {
            int x = a >> i + i & 3;
            if (x != 3) cout << char(i + 'A') << " is " << s[x] << "." << endl;
        }
        int x = a >> 10 & 3;
        if (x != 3) cout << "It is " << (x ? "night." : "day.") << endl;
        cout << endl;
    }
}