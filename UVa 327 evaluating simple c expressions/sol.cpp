#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
vector<char>var;
deque<int>que;
const int MAXN = 120;
char str[MAXN];
int val[26]; // 用来保存a,b,……z的初始值
int increment;
// 对输入的字符串进行过滤，消去空格
void Filter()
{
    int pos = 0;
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] != ' ')
        {
            str[pos++] = str[i];
        }
    }
    str[pos] = 0; // 字符串结束标志'\0'
}
// 是否有前缀
inline bool havePrefix(int i)
{
    if (str[i - 1] == '+' && str[i - 2] == '+' || str[i - 1] == '-' && str[i - 2] == '-')
        return true;
    return false;
}
// 是否有后缀
inline bool haveSuffix(int i)
{
    if (str[i + 1] == '+' && str[i + 2] == '+' || str[i + 1] == '-' && str[i + 2] == '-')
        return true;
    return false;
}
void PreProsess()
{
    increment = 0;
    while (!que.empty()) que.pop_back();
    var.clear();
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // 有前缀
            var.push_back(str[i]);  // 把该字母存入
            if (i >= 2 && havePrefix(i))
            {
                if (str[i - 1] == '+')
                    ++val[str[i] - 'a'];
                else
                    --val[str[i] - 'a'];
                int n = val[str[i] - 'a'];
                que.push_back(n);
                str[i - 1] = str[i - 2] = ' ';
            }
            // 有后缀
            else if (i <= strlen(str) - 3 && haveSuffix(i))
            {
                int n = val[str[i] - 'a'];
                que.push_back(n);
                if (str[i + 1] == '+')
                {
                    ++val[str[i] - 'a'];
                    --increment;
                }
                else
                {
                    --val[str[i] - 'a'];
                    ++increment;
                }
                str[i + 1] = str[i + 2] = ' ';
            }
            else
            {
                int n = val[str[i] - 'a'];
                que.push_back(n);
            }
        }
    }
}
int GetSum()
{
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == '+' || str[i] == '-')
        {
            int a = que.front();
            que.pop_front();
            int b = que.front();
            que.pop_front();
            if (str[i] == '+')
                que.push_front(a + b);
            else
                que.push_front(a - b);
        }
    }
    return que.front();
}
void Solve()
{
    // 给a,b,c……z 初始值
    for (int i = 0; i < 26; ++i)
    {
        val[i] = i + 1;
    }
    Filter();
    PreProsess();
    int sum = GetSum();
    //  puts(str);
    printf("    value = %d\n", sum);
    sort(var.begin(), var.begin() + var.size());
    for (int i = 0; i < var.size(); ++i)
    {
        printf("    %c = %d\n", var[i], val[var[i] - 'a']);
    }
    //   printf("\n");
}
int main()
{
    while (gets(str))
    {
        printf("Expression: %s\n", str);
        Solve();
    }
    return 0;
}