#include "origin.h"

int findAndDelete(SeqList &L)
{
    int min = L.data[0];
    int pos;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < min)
        {
            min = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length-1];
    L.length -= 1;
    return min;
}
