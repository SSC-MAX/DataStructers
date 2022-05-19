#include <stdio.h>

/*
*   括号匹配问题
*   实际问题中，由于后出现的左括号总是优先被匹配，所以可以利用栈的特性来解决
*   流程：
        1.若不为空，就继续扫描
        2.扫描到左括号时，压入栈顶
        3.扫描到右括号时，出栈左括号进行匹配，若栈空，匹配失败
        4.扫描结束时，若栈未空，仍是匹配失败
*/

#define maxLength 10
typedef struct          //定义栈的结构
{
    char data[maxLength];
    int top;
}SqStack;

void initStack(SqStack &S)   //初始化栈
{
    S.top = -1;
}

bool isEmpty(SqStack S)    //栈判空
{
    return S.top == -1;
}

bool push(SqStack &S, char x)   //压栈
{
    if (S.top == maxLength-1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool pop(SqStack &S, char &x)   //出栈
{
    if (isEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    S.top -= 1;
    return true;
}

bool bracketCheck(char str[], int length)  //括号匹配
{
    SqStack S;
    int i;
    char c;
    initStack(S);
    for (i = 0; i < length; i++)
    {
        if (str[i]=='(' || str[i]=='{' || str[i]=='[')  //发现左括号，入栈
        {
            push(S,str[i]);
        }else        //扫描到右括号
        {
            if (isEmpty(S))    //若栈为空，匹配失败
            {
                return false;
            }
            pop(S,c);      //栈非空，比较栈顶括号与此右括号
            if (str[i]=='}' && c!='{')
            {
                return false;
            }
            if (str[i]==']' && c!='[')
            {
                return false;
            }
            if (str[i]==')' && c!='(')
            {
                return false;
            }
        }
    }
    if (!isEmpty(S))   //扫描结束，若栈为空，匹配成功，否则失败
    {
        return false;
    }
    return true;
    
}

