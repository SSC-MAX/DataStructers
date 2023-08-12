#include <stdio.h>
#define MaxSize 10

/*
*   循环队列（即使用静态数组实现的顺序存储的队列）
*   当有元素出队时，由于队头指针需要后移，会导致队头指针前面出现空余的空间
    通过队尾指针+1再取模使得队尾指针可以回到队头指针的前面利用空间，实现了一种类似循环的结构
    但是这样会浪费一个存储空间，否则队满与队空的情况都是front==rear，无法区分
*   如果要求判满时不能浪费空间，可以有以下方法：
        1. 在结构中加入size保存当前队列元素的个数，以此来进行判满/判空
        2. 在结构中加入tag，每次插入都令tag=1，每次删除都令tag=0，由于只有出队会使队列变空，
           只有入队会使队列变满，可以以此&&队头队尾来判空/判满
*   如果队尾指针指向最后一个元素，需要先+1取模后再赋值，且初始化时令rear为MaxSize-1
    判满时需要原结果+1再比较是否与队头指针相等，核心思想在于得出队尾指针的下一位，
    即比较下一个插入位置的下一个是否是队头
    计算元素个数时，同样需要在原结果上+1
*/

typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //存放元素的数组
    int front, rear;        //对头与队尾,队头指向第一个元素，队尾指向最后一个元素的下一位（下一个插入的位置）
} SqQueue;

//初始化
void InitQueue(SqQueue &Q)
{
    //队头与队尾都指向 0
    Q.rear = 0, Q.front = 0;
}

//判断队列已空
bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return true;
    }
    return false;
}

//判断队列已满
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize == MaxSize; //即下一个应该存储元素的位置已经是队头，这样会导致实际存储的元素个数为MaxSize-1
}
//当队尾指向队列最后一位元素时，判断队列已满
bool QueueFullInLast(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize + 1 == MaxSize; //核心都是得出下一位
}

//入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if (QueueFull(Q)) //队列已满
    {
        return false;
    }
    Q.data[Q.rear] = x;              //赋值
    Q.rear = (Q.rear + 1) % MaxSize; //队尾后移一位,取模是为了当原队头前有空间时让新的元素添加到原队头的前面去
    return true;
}

//出队（用x保存值）
bool OutQueue(SqQueue &Q, ElemType x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize; //同理队尾，实现循环
    return true;
}

//获取队头元素（用x保存）
bool getHead(SqQueue &Q, ElemType &x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

//获取队列个数
int getSize(SqQueue Q)
{
    return (Q.front + MaxSize - Q.front) % MaxSize;
}
//当队尾指针指向最后一个元素时获取队列个数
int getSizeInLast(SqQueue Q)
{
    return (Q.front + MaxSize - Q.front) % MaxSize + 1;
}