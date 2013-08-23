#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main()
{
    int cc = 1;
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<string> mapbk;
        map<string, int> map;
        char g[200][200];
        for (int i = 0; i < 200; i++)
            for (int j = 0; j < 200; j++)
                g[i][j] = 0;
        int top = 0;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            int first = top;
            for (int j = 0; j < m; j++)
            {
                string s;
                cin >> s;
                map[s] = top;
                mapbk.push_back(s);
                top++;
            }
            for (int j = first; j < top - 1; j++)
                g[j][j + 1] = 1;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            g[map[s1]][map[s2]] = 1;
        }
        for (int k = 0; k < top; k++)
            for (int i = 0; i < top; i++)
                for (int j = 0; j < top; j++)
                    g[i][j] |= g[i][k] & g[k][j];
        string out = "";
        int count = 0;
        for (int i = 0; i < top; i++)
            for (int j = i + 1; j < top; j++)
            {
                if (!g[i][j] && !g[j][i])
                {
                    count++;
                    if (count <= 2)
                        out = out + "(" + mapbk[i] + "," + mapbk[j] + ") ";
                }
            }
        if (count != 0)
        {
            cout << "Case " << cc++ << ", " << count << " concurrent events:"
                 << endl;
            cout << out << endl;
        }
        else
        {
            cout << "Case " << cc++ << ", no concurrent events." << endl;
        }
    }
    return 0;
}