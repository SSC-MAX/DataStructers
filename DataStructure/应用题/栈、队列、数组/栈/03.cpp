#include <stdio.h>

bool ifIllegal(char* operation, int len)
{
    int count = 0;
    for (int i=0;i<len;i++)
    {
        if (operation[i] == 'I')
        {
            count += 1;
        if (operation[i] == 'O')
        {
            count -= 1;
        }
        if (count < 0)
        {
            return false;
        }
    }
    return true;
    
}