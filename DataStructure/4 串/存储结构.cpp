#include <stdio.h>
#define Length 100

typedef struct 
{
    char data[Length];
    int length;
}SString;

int strCompare(SString str1, SString str2)
{
    for (int i = 0; i < str1.length && i < str2.length; i++)
    {
        if (str1.data[i] != str2.data[i])
        {
            return str1.data[i] - str2.data[i];
        }
    }
    return str1.length - str2.length;
}