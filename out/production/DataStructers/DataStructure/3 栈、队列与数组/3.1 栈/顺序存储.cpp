#include <stdio.h>
#define MaxSize 10

typedef struct 
{
    int data[MaxSize]; //静态数组存放栈中元素
    int top;        //栈顶指针（但并不是真正意义上C语言中的指针
} SqStack;

/*
* 共享栈
*   两个栈共享一片存储空间，使用两个栈顶指针分别指向各自的栈顶
*   栈满条件：top0 + 1 = top1
*/
typedef struct 
{
    int data[MaxSize];
    int top0;
    int top1;
} ShStack;


//初始化
void initStack(SqStack &S)
{
    S.top = -1;    //初始化栈顶指针，由于此时没有元素，所以指向-1
}

//初始化共享栈
void initShStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;   //从顶部开始
}

//判空
bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

//进栈
bool Push(SqStack &S, int x)
{
    if (S.top==MaxSize-1)
    {
        return false;   //栈已满
    }
    S.top = S.top + 1;    //栈顶向后一位
    S.data[S.top] = x;    //元素进栈
    return true;
}

//出栈
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;  // 栈为空
    }
    x = S.data[S.top];   //保存栈顶元素
    S.top--;     //栈顶向下一位，并没有真正删除栈顶元素，只在逻辑上删除
    return true;
}

//获取栈顶元素
bool GetTop(SqStack S, int x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}



