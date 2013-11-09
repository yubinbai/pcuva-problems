#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n, m;
string line;
string number;
string data[MAXN];
int main()
{
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        if (x)
            cout << endl;
        scanf("%d\n", &m);
        for (int j = 0; j < m; j++)
        {
            getline(cin, line);
            data[j] = "";
            for (int k = 0; k < line.size(); k++)
            {
                char ch = line[k];
                if (ch == '-')
                    continue;
                if (isalpha(ch))
                {
                    if (ch > 'Q')
                        ch--;
                    ch = (ch - 'A') / 3 + 2 + '0';
                }
                data[j] += ch;
                if (data[j].size() == 3)
                    data[j] += '-';
            }
        }
        bool Nod = true;
        sort(data, data + m);
        int s = 1;
        for (int i = 0; i < m; i++)
            if (data[i] == data[i + 1]) s++;
            else
            {
                if (s > 1)
                {
                    cout << data[i] << " " << s << endl;
                    Nod = false;
                }
                s = 1;
            }
        if (Nod)
            printf("No duplicates.\n");
    }
    return 0;
}