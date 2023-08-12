#include "origin.h"

SeqList mergeSequeueList(SeqList L1, SeqList L2, SeqList &L3)
{
    int i,j,k=0;
    while (i<L1.length && j<L2.length)
    {
        if (L1.data[i] < L2.data[j])
        {
            L3.data[k] = L1.data[i];
            i++;
        }else 
        {
            L3.data[k] = L2.data[j];
        }
        k++;
    }
    if (L1.length-i>0)
    {
       while (k<L1.length)
       {
           L3.data[k] = L1.data[i];
           k++;
           i++;
       }  
    }
    if (L2.length-j>0)
    {
        while (k<L2.length)
        {
            L3.data[k] = L2.data[j];
            k++;
            j++;
        }
    }
    L3.length = k;
    return L3;
    
}