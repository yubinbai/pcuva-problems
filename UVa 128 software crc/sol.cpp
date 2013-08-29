#include <stdio.h>

#define MAX_LINE_LEN 1025
#define CRC_MOD 34943

int main()
{
    int nCRC;
    char *psz, szLine[MAX_LINE_LEN];

    while (gets(szLine) && *szLine != '#')
    {
        for (nCRC = 0, psz = szLine; *psz; psz++)
            nCRC = ((nCRC << 8) + *psz) % CRC_MOD;

        nCRC = ((nCRC << 8) + 0) % CRC_MOD;
        nCRC = ((nCRC << 8) + 0) % CRC_MOD;

        nCRC = (CRC_MOD - nCRC) % CRC_MOD;
        printf("%02X %02X\n", nCRC >> 8, nCRC & 0xFF);
    }

    return 0;
}