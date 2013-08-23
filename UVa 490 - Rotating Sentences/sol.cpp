#include<iostream>
#include<cstring>
using namespace std;
char a[110][110];
int main()
{
    int i = 0, j, line = 0, max = 0, len;
    while (!cin.eof())
    {
        cin.getline(a[i++], 110);
        len = strlen(a[i - 1]);
        ++line; if (max < len) max = len;
    }
    for (i = 0; i < max; ++i)
    {
        for (j = line - 2; j >= 0; j--) //line-2是因为最后读的一行为空行
            if (a[j][i] == '\0' || a[j][i] == '\n') //这里是关键
                cout << " ";
            else cout << a[j][i];
        cout << endl;
    }
    return 0;
}