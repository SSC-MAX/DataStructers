#include <stdio.h>

/*
*   KMP算法
    当第k位发生不匹配，说明前k-1位都能匹配上
    找到第k-1位的元素，在模式串中找到        
*/

typedef struct 
{
    char ch[100];
    int length;
}SString;

/*
    next数组求法
    当第k位发生不匹配时，令其前k-1个字符组成字符串S
    next[k] = S最长相等前后缀长度+1
    可以发现，无论什么样的模式串，其next[1]=0,next[2]=1
*/
void getNextArr(SString T, int next[])
{
    int i=1,j=0;
    next[1] = 0;
    while (i<T.length)
    {
        if (j==0 || T.ch[i] == T.ch[j])
        {
            ++i,++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

int index_KMP(SString S, SString T, int next[])
{
    int i=1,j=0;
    while (i<S.length && j<T.length)
    {
        if (j==0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if (j>T.length)
    {
        return i-T.length;
    }else{
        return 0;
    }
}