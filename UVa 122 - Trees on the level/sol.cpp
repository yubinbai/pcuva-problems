#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

struct NODE
{
    int nVal;
    NODE *pL;
    NODE *pR;
}

const NullNode = {0, 0, 0};

void DeleteTree(NODE *pPar)
{
    if (pPar != NULL)
    {

        DeleteTree(pPar->pL), DeleteTree(pPar->pR);
    }
    delete pPar;
}

NODE *AddChild(NODE *pPar, int nVal, const char *pPath)
{

    if (pPar == 0)
    {
        pPar = new NODE(NullNode);
    }

    switch (*pPath)
    {

    case ')': pPar->nVal = (pPar->nVal == 0 && nVal != 0) ? nVal : -1; break;

    case 'L': pPar->pL = AddChild(pPar->pL, nVal, pPath + 1); break;
    case 'R': pPar->pR = AddChild(pPar->pR, nVal, pPath + 1); break;
    }
    return pPar;
}

int main(void)
{

    NODE *pRoot = 0;

    for (string strToken; cin >> strToken;)
    {

        const char *pStr = strToken.c_str();
        int nLen = strToken.length(), nVal = 0;

        if (pStr[1] != ')')
        {

            for (; isdigit(*++pStr); nVal = nVal * 10 + *pStr - '0');
            if (*pStr != ',') while (true);

            pRoot = AddChild(pRoot, nVal, ++pStr);
            continue;
        }
        list<NODE *> Level(1, pRoot);
        stringstream ssResult;

        for (list<NODE *>::iterator i = Level.begin(); !Level.empty();

                i = (i == Level.end() ? Level.begin() : i))
        {

            NODE *pTemp = *i;
            i = Level.erase(i);

            if (pTemp == 0)
            {
                continue;
            }

            if (pTemp->nVal <= 0)
            {

                Level.clear();
                ssResult.str("");
                break;
            }

            ssResult << pTemp->nVal << ' ';
            i = Level.insert(i, pTemp->pL), ++i;
            i = Level.insert(i, pTemp->pR), ++i;
        }

        DeleteTree(pRoot);
        pRoot = 0;
        strToken = ssResult.str();

        if (strToken.empty())
        {
            strToken = "not complete";
        }
        else
        {
            strToken.erase(strToken.end() - 1);
        }

        cout << strToken << endl;
    }
    return 0;
}