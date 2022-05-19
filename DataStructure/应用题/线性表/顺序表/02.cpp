#include "origin.h"

void reverseElement(SeqList &L)
{
    int exchangeElement;
    for (int i = 0; i <= L.length/2; i++)
    {
        exchangeElement = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = exchangeElement;
    }
}