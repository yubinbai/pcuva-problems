#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int t[128];
char f[16];

void init()
{
    f[0] = '0';
    f[1] = '1';
    f[2] = '2';
    f[3] = '3';
    f[4] = '4';
    f[5] = '5';
    f[6] = '6';
    f[7] = '7';
    f[8] = '8';
    f[9] = '9';
    f[10] = 'A';
    f[11] = 'B';
    f[12] = 'C';
    f[13] = 'D';
    f[14] = 'E';
    f[15] = 'F';
    t['0'] = 0;
    t['1'] = 1;
    t['2'] = 2;
    t['3'] = 3;
    t['4'] = 4;
    t['5'] = 5;
    t['6'] = 6;
    t['7'] = 7;
    t['8'] = 8;
    t['9'] = 9;
    t['A'] = 10;
    t['B'] = 11;
    t['C'] = 12;
    t['D'] = 13;
    t['E'] = 14;
    t['F'] = 15;
}


bool isLegal(string value, int base)
{
    int error = 0;
    for (int i = 0; i < value.size(); i++)
        if (!(t[value[i]] < base))error++;
    return error ? false : true ;
}

long long decode(string value, int base)
{
    long long sum = 0;
    for (int i = 0; i < value.size(); i++)
    {
        sum *= base;
        sum += t[value[i]];
    }
    return sum;
}

string encode(long long value, int base)
{
    if (value)
    {
        string s = encode(value / base, base);
        s.push_back(f[value % base]);
        return s;
    }
    else
    {
        return "";
    }
}


int main()
{
    int ob;
    int db;
    string dv;
    string ov;
    init();
    while (cin >> ob >> db >> ov)
    {
        if (!isLegal(ov, ob))
        {
            printf("%s is an illegal base %d number\n",
                   ov.c_str(), ob);
        }
        else
        {
            long long x = decode(ov, ob);
            dv = encode(x, db);
            if (dv == "")dv = "0";
            printf("%s base %d = %s base %d\n",
                   ov.c_str(), ob, dv.c_str(), db);
        }
    }
    return 0;
}