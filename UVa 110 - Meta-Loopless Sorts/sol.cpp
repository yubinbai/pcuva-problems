/*
关键在于如何生成给定数量元素的全排列，很自然的使用递归算法。考虑n = 3的情况，
相应的3个变量为a, b, c。在结果集里加入a作为初始化，之后b可以在a前面或后面2种位置
可以插入，分别代表b < a或b > a的情况。这样就可以生成第1级的if-else语句，并递归调用至2级。
对于"ba"顺序的结果集，c有三种位置可以插入，对应的语句应该是：

if c < b then
...
else if c < a then
...
else
...
由此生成第2级的if-else语句。再递归调用至第3级，发现已到达最高级，输出结果并返回。

这道题有一个需要特别注意的地方，生成的第一道代码前不要有任何空行，每段代码后也不要紧跟着空行。
而是从第二段代码开始，头部需要加一个空行。如果没有注意这个问题，会得到PE。
*/
#include <iostream>
#include <string>
using namespace std;
const char *pVars = "abcdefgh";
const char *Indent(int nCnt)
{
    static const char *pSpaces[] = { "",
                                     "  ", "    ", "      ", "        ", "        ", "          ",
                                     "            ", "              ", "                "
                                   };
    return pSpaces[nCnt];
}
void MetaSort(int currLevel, int maxLevel, string &strOrder)
{
    if (currLevel == maxLevel)
    {
        cout << Indent(currLevel) << "writeln(" << strOrder[0];
        for (size_t i = 1; i < strOrder.size(); ++i)
        {
            cout << ',' << strOrder[i];
        }
        cout << ")\n";
        return;
    }
    cout << Indent(currLevel);
    for (size_t i = 0; i < strOrder.size(); ++i)
    {
        cout << "if " << pVars[currLevel] << " < " << strOrder[i] << " then\n";
        strOrder.insert(i, pVars + currLevel, 1);
        MetaSort(currLevel + 1, maxLevel, strOrder);
        strOrder.erase(i, 1);
        cout << Indent(currLevel) << "else ";
    }
    cout << endl;
    strOrder.insert(strOrder.size(), pVars + currLevel, 1);
    MetaSort(currLevel + 1, maxLevel, strOrder);
    strOrder.erase(strOrder.size() - 1, 1);
}
int main(void)
{
    int nProgs, nVars;
    cin >> nProgs;
    for (int j = 0; j < nProgs; ++j)
    {
        cin >> nVars;
        if (j != 0)
        {
            cout << endl;
        }
        string strVarDec = "a";
        for (int i = 1; i < nVars; ++i)
        {
            strVarDec.push_back(',');
            strVarDec.push_back(i + 'a');
        }
        cout << "program sort(input,output);\nvar\n" << strVarDec
             << " : integer;\nbegin\n  readln(" << strVarDec << ");\n";
        string strInit("a");
        MetaSort(1, nVars, strInit);
        cout << "end." << endl;
    }
    return 0;
}