#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> setNum;
int main()
{
    char c; int count = 1;
    while (scanf("%c", &c) != EOF)
    {
        setNum.clear();
        while (c != '9')
        {
            string vTemp;
            while (c != '\n')
            {
                vTemp.insert(vTemp.end(), c);
                scanf("%c", &c);
            }
            setNum.push_back(vTemp);
            scanf("%c", &c);
        }
        sort(setNum.begin(), setNum.end());
        bool prefix = false;
        for (int i = 0; i < setNum.size(); i++)
        {
            for (int j = i + 1; j < setNum.size(); j++)
            {
                size_t str = setNum[j].find(setNum[i]);
                if (str == 0)
                {
                    prefix = true;
                    break;
                }
            }
            if (prefix)
                break;
        }
        if (prefix)
            printf("Set %d is not immediately decodable\n", count);
        else
            printf("Set %d is immediately decodable\n", count);
        count++;
        if (scanf("%c", &c) == EOF)
            break;
    }
    return 0;
}
