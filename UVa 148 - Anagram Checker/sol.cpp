#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct WORD
{
    string str; char Trait[26];
    bool operator>=(const WORD &Other)   //比较两个单词的特征，确定是否包含
    {
        int i = 0;
        for (; i < 26 && Trait[i] >= Other.Trait[i]; ++i);
        return (i == 26); //全部特征都大于或等于时，判定存在包含关系
    }
    WORD &operator-=(const WORD &Other)   //从前一个单词中减掉后面的单词
    {
        for (int i = -1; ++i < 26; Trait[i] -= Other.Trait[i]); //特征操作
        return *this;
    }
    WORD &operator+=(const WORD &Other)   //在前面一个单词中加上后面的单词
    {
        for (int i = -1; ++i < 26; Trait[i] += Other.Trait[i]); //特征操作
        return *this;
    }
};
void GenTrait(const char *Str, char *Trait)   //根据字符串生成特征
{
    for (fill(&Trait[0], &Trait[26], 0); *Str != 0; ++Trait[*Str++ - 'A']);
}
typedef vector<WORD>::const_iterator DICTITER;
//递归搜索，iBeg和iEnd为搜索字典段的起点和终点。字典必须有序
void SearchAnagram(DICTITER iBeg, DICTITER iEnd, WORD &Phrase)
{
    int nZeroCnt = 0;
    string &str = Phrase.str;
    //判断短语中所有字母是否都以在字典中找到
    for (; nZeroCnt < 26 && Phrase.Trait[nZeroCnt] == 0; ++nZeroCnt);
    if (nZeroCnt == 26)   //所有字母都找到，输出结果
    {
        istringstream ss(str); //判定找到的单词集是否和原单词集相同
        vector<string> SrcWords, GenWords;
        //从输出字符串中提取原短语中的单词列表和查找到的单词集
        for (string Word; ss >> Word && Word != "="; SrcWords.push_back(Word));
        for (string Word; ss >> Word; GenWords.push_back(Word));
        //对原短语中的单词列表排序。查找到的单词集已有序
        sort(SrcWords.begin(), SrcWords.end());
        if (SrcWords != GenWords)   //判定是否相同
        {
            cout << str << endl; //不同时输出结果
        }
        return; //返回上一级调用
    }
    //从指定的开始到结束，查找字典段中是否有单词被短语包含
    for (DICTITER i = iBeg; i != iEnd; ++i)
    {
        if (Phrase >= *i)   //根据特征进行查找
        {
            Phrase -= *i; //将该单词的特征从短语特征中减掉
            str.push_back(' '); //结果字符串的最后加上该短语
            str.append(i->str);
            SearchAnagram(i + 1, iEnd, Phrase); //进入下一级查找过程
            str.erase(str.length() - i->str.length() - 1); //恢复结果字符串
            Phrase += *i; //恢复短语特征
        }
    }
}
//主函数
int main(void)
{
    vector<WORD> Dict, Subset;
    //读入所有字典，并生成每个单词的特征
    for (WORD Word; cin >> Word.str && Word.str != "#";)
    {
        GenTrait(Word.str.c_str(), Word.Trait);
        Dict.push_back(Word);
    }
    //读入所有的短语，逐个处理
    for (string Line; getline(cin, Line) && Line != "#"; Subset.clear())
    {
        WORD Phrase = {Line}; //保留原短语字符串
        //删除指定短语中的空格(准备生成特征)
        Line.erase(remove(Line.begin(), Line.end(), ' '), Line.end());
        if (Line.empty())
        {
            continue;
        }
        GenTrait(Line.c_str(), Phrase.Trait); //生成特征
        //在字典中筛选中被原短语包含的单词，用作查找
        for (vector<WORD>::iterator i = Dict.begin(); i != Dict.end(); ++i)
        {
            if (Phrase >= *i)   //根据特定判断是否被包含
            {
                Subset.push_back(*i);
            }
        }
        Phrase.str.append(" ="); //按照格式，在原短语后加上空格和=号
        SearchAnagram(Subset.begin(), Subset.end(), Phrase); //递归查找过程
    }
    return 0;
}
