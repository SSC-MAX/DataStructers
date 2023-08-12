#include <stdio.h>
typedef struct 
{
    int data[100];
    int length;
} SeqList;

void initSeqList(SeqList &L)
{
    L.length = 8;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 3;
    L.data[4] = 3;
    L.data[5] = 4;
    L.data[6] = 5;
    L.data[7] = 6;
    L.data[8] = 7;
}

void printSeqList(SeqList L)
{
    for (int i = 0; i <= L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}