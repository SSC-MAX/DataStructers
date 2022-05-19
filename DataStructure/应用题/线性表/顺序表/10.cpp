#include <stdio.h>

/*
* 时间复杂度：O(n)
* 空间复杂度: O(1)
*/
void reverse(int arr[], int start, int end)
{
    int exchange;
    while (start < end)
    {
        exchange = arr[start];
        arr[start] = arr[end];
        arr[end] = exchange;
        start ++;
        end --;
    }
    
}


void moveElement(int R[],int n,int p)
{
   reverse(R,0,n-1);
   reverse(R,0,n-p-1);
   reverse(R,n-p,n-1);
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    moveElement(arr,5,2);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}