#include <stdio.h>
#include <stdlib.h>

/*
* O(nlog<2>n)
* O(1)
*/

int cmp(const void*_a, const void* _b)
{
    int a = *(int*)_a;
    int b = *(int*)_b;
    return a-b;
}

void getMainElement(int A[], int arraySize)
{
    qsort(A,arraySize,sizeof(int),cmp);
    int count = 0;
    int x ;
    for (int i = 0; i < arraySize-1; i++)
    {
        
        if (A[i]==A[i+1])
        {
            count = 1;
            int j=i+1;
            while (A[i]==A[j]&&j<arraySize)
            {
                count += 1;
                j++;
            }
            if (count>arraySize/2)
            {
                x = A[i];
                break;
            }
        }
    }
    if (count!=0)
    {
        printf("%d",x);
    }else{
        printf("%d",-1);
    }
}

int main()
{
    int A[5] = {1,1,1,2,3};
    getMainElement(A,5);
}
