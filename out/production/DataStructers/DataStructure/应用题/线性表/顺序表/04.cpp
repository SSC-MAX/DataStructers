#include "origin.h"

bool deleteElement(SeqList &L, int s, int t)
{
    if (s<1 || t>L.length || s>t)
    {
        printf("输入值错误");
        return false;
    }
    L.length -= s-t-1;
    for (int i = s; i < L.length; i++)
    {
        L.data[i] = L.data[t-1];
        t+=1;
    }
    return true;
}