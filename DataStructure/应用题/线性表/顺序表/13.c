#include <stdio.h>
#include <stdlib.h>

int findMinElement(int A[], int length)
{
    int* B;
    B=(int*)malloc(length*sizeof(int));
    for (int i = 0; i < length; i++)
    {
        B[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (A[i]>0&&(A[i]<length||A[i]==length))
        {
            B[A[i]-1] = A[i];
        }
    }
    for (int j = 0; j < length; j++)
    {
        if (B[j]==0)
        {
            return j+1;
        }
    }
    return length+1;
}