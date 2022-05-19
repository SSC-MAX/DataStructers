#include <stdio.h>

int getAncestor(int tree[], int i, int j)
{
    char str = 'a';
    while (i!=1 && j!=1)
    {
        if (tree[i]==tree[j])
        {
            return i;
        }
        
        if (i<j)
        {
            j=j/2;
        }else
        {
            i = i/2;
        }
        
    }
    return 1;
}