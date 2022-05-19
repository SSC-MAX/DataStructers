#include "origin.h"

void reverse(int A[],int left, int right,int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ",A[i]);
    }
    printf("------\n");
    int exchange;
    while (left < right)
    {
        exchange = A[left];
        A[left] = A[right];
        A[right] = exchange;
        left ++;
        right --;
    }
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void changePosition(int A[], int m , int n, int arraySize)
{
    reverse(A,0,arraySize-1,arraySize);
    reverse(A,0,n-1,arraySize);
    reverse(A,n,arraySize-1,arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ",A[i]);
    }
    
}

int main()
{
    int A[] = {1,2,3,4,5,6,7,8};
    changePosition(A,3,5,8);
}


   
