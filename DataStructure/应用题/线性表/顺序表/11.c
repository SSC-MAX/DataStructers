#include <stdio.h>

/*
* 时间复杂度: O(n)
* 空间复杂度 O(1)
*/
int findMiddleNum(int A[], int B[],int num)
{
    int i=0,j=0,k=0;
    int middleNum;
    int C[num];
    while (i<=num && j<=num)
    {
        
        if (A[i]<B[j])
        {
           
            C[k] = A[i];
             printf("A[i]<B[j],A[i]=%d,B[j]=%d,C[k]=%d",A[i],B[j],C[k]);
            printf("\n");
            i++;
        }else{
            
            C[k] = B[j];
            printf("A[i]>B[j],A[i]=%d,B[j]=%d,C[k]=%d",A[i],B[j],C[k]);
            printf("\n");
            j++;
        }
        k++;
    }
    
    while (i<num)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j<num)
    {
        C[k] = B[j];
        j++;
        k++;
    }

    middleNum = C[k/2];
    for (int m = 0; m < k; m++)
    {
       printf("%d ",C[m]);
    }
    printf("\n");
    
    return middleNum;
}

int main()
{
    int A[5] = {11,13,15,17,19};
    int B[5] = {2,4,6,8,20};
    int middleNum = findMiddleNum(A,B,5);
    printf("%d",middleNum);
}