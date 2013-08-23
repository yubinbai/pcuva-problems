#include <string>
#include <set>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    const int nr_chr_max = 256;
    char word[nr_chr_max + 1];
    set<string> words;
    while (scanf("%s", word) != EOF)
        for (int i = 0, length = strlen(word); i < length; /* i++ */)
        {
            while (i < length && !isalpha(word[i]))
                i++;
            if (i == length)
                break;
            int j = 0;
            char w[nr_chr_max + 1];
            for ( ; i < length && isalpha(word[i]); i++, j++)
                w[j] = static_cast<char>(tolower(word[i]));
            w[j] = '\0';
            words.insert(string(w));
        }
    for (set<string>::const_iterator i = words.begin(), e = words.end();
            i != e; ++i)
        printf("%s\n", (*i).c_str());
    return 0;
}