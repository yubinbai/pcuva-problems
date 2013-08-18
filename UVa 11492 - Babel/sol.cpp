#include <cstdio>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int SIZE = 55, SIZE_C = 4005, IMPOSSIBLE = -1, NOT_USED = 0, USED = -1;
int N;
char cstr1[SIZE], cstr2[SIZE], cstr3[SIZE];
string strBegin, strEnd;
map< string, int > M, W;

struct Entry
{
    string word;
    int len, no;
};

struct Compare
{
    bool operator () (const Entry &e1, const Entry &e2)
    {
        return e1.len > e2.len;
    }
};

vector< Entry > vec1d;
vector< vector< Entry > > vec2d(SIZE_C, vec1d);

priority_queue< Entry, vector< Entry >, Compare > q;

void input()
{
    scanf("%s%s", cstr1, cstr2);
    strBegin = (string)cstr1;
    strEnd = (string)cstr2;
    for (int i = 0; i < SIZE_C; ++i)
    {
        vec2d[i].clear();
    }
    M.clear();
    W.clear();
    while (N--)
    {
        scanf("%s%s%s", cstr1, cstr2, cstr3);
        string s1 = (string)cstr1;
        string s2 = (string)cstr2;
        string s3 = (string)cstr3;
        int no1 = M.size();
        if (M.count(s1))
        {
            no1 = M[s1];
        }
        else
        {
            M.insert(pair< string, int >(s1, no1));
        }
        Entry new_entry;
        new_entry.word = s3;
        new_entry.no = no1;
        new_entry.len = s3.length();
        vec2d[no1].push_back(new_entry);

        int no2 = M.size();
        if (M.count(s2))
        {
            no2 = M[s2];
        }
        else
        {
            M.insert(pair< string, int >(s2, no2));
        }
        Entry new_entry2;
        new_entry2.word = s3;
        new_entry2.no = no2;
        new_entry2.len = s3.length();
        vec2d[no2].push_back(new_entry2);

        W.insert(pair< string, int >(s3, no1 * SIZE_C + no2));
    }
}

int spfa(int begin_c, int end_c)
{
    if (begin_c == end_c)
        return 0;
    while (!q.empty())
        q.pop();
    for (int i = 0, j = vec2d[begin_c].size(); i < j; ++i)
    {
        Entry old_entry = vec2d[begin_c][i];
        q.push(old_entry);
    }
    int min_len = SIZE_C * SIZE;
    while (!q.empty())
    {
        Entry old_entry = q.top();
        q.pop();
        char initial_c = old_entry.word[0];
        int num = W[old_entry.word];
        if (num == USED)
            continue;
        W[old_entry.word] = USED;
        int no1 = num / SIZE_C;
        int no2 = num % SIZE_C;
        if (no1 == end_c || no2 == end_c)
        {
            if (min_len > old_entry.len)
            {
                min_len = old_entry.len;
            }
            continue;
        }
        if (old_entry.no == no1)
        {
            for (int i = 0, j = vec2d[no2].size(); i < j; ++i)
            {
                Entry new_entry = vec2d[no2][i];
                if (new_entry.word[0] != initial_c)
                {
                    new_entry.len += old_entry.len;
                    q.push(new_entry);
                }
            }
        }
        else
        {
            for (int i = 0, j = vec2d[no1].size(); i < j; ++i)
            {
                Entry new_entry = vec2d[no1][i];
                if (new_entry.word[0] != initial_c)
                {
                    new_entry.len += old_entry.len;
                    q.push(new_entry);
                }
            }
        }
    }
    if (min_len < SIZE_C * SIZE)
    {
        return min_len;
    }
    return IMPOSSIBLE;
}

void output()
{
    int result;
    if (!M.count(strBegin) || !M.count(strEnd))
    {
        puts("impossivel");
    }
    else if ((result = spfa(M[strBegin], M[strEnd])) >= 0)
    {
        printf("%d\n", result);
    }
    else
    {
        puts("impossivel");
    }
}

int main()
{
    while (~scanf("%d", &N) && N > 0)
    {
        input();
        output();
    }
    return 0;
}