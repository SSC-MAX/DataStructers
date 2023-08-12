#include <stdio.h>

typedef struct 
{
    char ch[100];
    int length;
}SString;

bool match(SString str1, SString str2)
{
    int k=1;
    int i=1,j=1;

    while (i<str1.length && j<str2.length)
    {
        if (str1.ch[i] == str1.ch[j])
        {
            i++;
            j++;
        }else
        {
            k+=1;    //也可以舍弃k，i=i-j+2，即向左偏回j个长度并算上自己和开头
            i = k;
            j = 1;
        }
    }
    if (j<str2.length)     //只有当模式串到达末尾，才说明匹配成功
    {
        return k;   
    }else
    {
        return false;    
    }
    
    
}
