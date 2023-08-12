#include "origin.h"

void deleteDepurtated(SeqList &L)
{
    int i,j;
    for (i = 0,j=1; j < L.length; i++,j++)
    {
        printf("此时,i=%d,j=%d,data[i]=%d,data[j]=%d\n",i,j,L.data[i],L.data[j]);
        if (L.data[i] == L.data[j])
        {
            printf("发现相等\n");
            for (int k = i; k < L.length; k++)
            {
                L.data[k] = L.data[k+1];
            }
            L.length -= 1;
            j--;
            i--;
            printSeqList(L);
        }
    }
}

int main()
{
    SeqList L;
    initSeqList(L);
    printSeqList(L);
    deleteDepurtated(L);
    printSeqList(L);
    return 0;
}