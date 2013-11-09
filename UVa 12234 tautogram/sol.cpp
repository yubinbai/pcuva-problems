#include <cstdio>
#include <cctype>
int main()
{
    char line[1100], *ptr, ch, word[21];
    while (gets(line) && line[0] != '*')
    {
        bool isTauto = true;
        int offset;
        ch = tolower(line[0]);
        ptr = line;
        while (sscanf(ptr, "%s%n", word, &offset) != EOF)
        {
            ptr += offset;
            if (tolower(word[0]) != ch)
            {
                isTauto = false;
                break;
            }
        }
        puts(isTauto ? "Y" : "N");
    }
    return 0;
}