#include <stdio.h>

/*
*   
*   可以使用前中后缀表达式来表示一个表达式的求值过程
*   后缀表达式（逆波兰表达式）
        运算符在两个运算元素之后
        中缀转后缀过程：
            1.明确各个运算符的顺序
            2.选择下一个运算符，将已经运算结束的两个元素视作整体
            ((15/(7-(1+1)))*3-(2+(1+1)))
*   算法实现
    使用栈来实现，对于后缀表达式：
        1.从左向右扫描，元素依次入栈
        2.扫描到运算符时出栈两个元素，进行计算，计算结果再次入栈
        3.循环往复直到结束
    可以发现，由于后缀表达式是从左向右扫描，所以先出栈的是右边的操作数
    前缀表达式同理，不过从右向左扫描，所以先出栈的是左边的操作数
*/

#define maxLength 100
typedef struct 
{
    char data[maxLength];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool isEmpty(SqStack S)
{
    return S.top == -1;
}

bool push(SqStack &S, char x)
{
    if (S.top == maxLength - 1)
    {
        return false;
    }
    
    S.data[++S.top] = x;
    return true;
}

bool pop(SqStack &S, char &x)
{
    if (isEmpty(S))
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

void getValue(char str[], int length)
{
    SqStack S;
    int i;
    InitStack(S);
    for (i = 0; i < length; i++)
    {
        if (str[i]!='+' && str[i]!='-' && str[i] != '*' && str[i]!='/')
        {
            push(S,str[i]);
            
        }
        
    }
    
}
