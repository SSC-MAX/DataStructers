#include "origin.h"

void findElement(SeqList &L,int x)
{
    int low=0,high=L.length-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (L.data[mid] == x)
        {
            printf("找到了:%d",x);
            break;
        }else{
            if (L.data[mid] < x)
            {
                low = mid+1;
            }else{
                high = mid-1;
            }
            
        }
        
    }
    if (L.data[mid] = x)
    {
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = x;
    }
    if (low>high)
    {
        for (int i = L.length; i > high; i--)
        {
            L.data[i] = L.data[i-1];
        }
        L.data[high+1] = x;
    }
    
    
}