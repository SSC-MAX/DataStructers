#include "origin.h"

void deleteElement(SeqList &L, int x)
{
    int k=0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}