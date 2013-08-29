# include <iostream>
# include <string>
# include <cstdio>
# include <cstdlib>
using namespace std;


int main(int argc, char const *argv[])
{

    string caseNum;
    getline(cin, caseNum);
    int n = atoi(caseNum.c_str());

    string blank;
    getline(cin, blank);        // 读取空行

    string amplitude;       // 振幅/高度
    string frequency;       // 重复次数

    for (int m = 0; m < n; m++)
    {
        getline(cin, amplitude);
        getline(cin, frequency) ;
        getline(cin, blank);    // 读取空行

        int a = atoi(amplitude.c_str());
        int f = atoi(frequency.c_str());

        for (int i = 0; i < f; i++)
        {
            // 上三角
            for (int j = 1; j <= a; j++)
            {
                for (int k = 1; k <= j; k++)
                {
                    cout << j;
                }
                cout << endl;
            }

            // 下三角
            for (int j = a - 1; j > 0; j--)
            {
                for (int k = j; k > 0; k--)
                {
                    cout << j;
                }
                cout << endl;
            }

            // 保证最后不会输出一个空行
            if (i != f - 1 || m != n - 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}