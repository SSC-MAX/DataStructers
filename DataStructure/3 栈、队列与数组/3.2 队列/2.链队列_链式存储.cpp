#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

/*
*   链队列
*   出队与入队操作可以看作是单链表的头删与尾插
*   需要有一个队头指针与队尾指针
        因为需要在队尾进行插入操作，添加一个队尾指针避免每次插入元素时都要从头遍历一次
*   在最后一个元素出队时，需要修改队列的头尾指针将队列设置为空队列的状态
*   链式存储除非内存空间不足，否则很难出现满队列的情况，所以不存在判满的问题
        ？？？？？？是不是说链式存储比顺序存储优秀很多，不需要顺序存储 ？？？？？？
*/

typedef struct LinkNode   //链式队列的结点
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct          //链式队列
{
    LinkNode *front, *rear;   //队头与队尾指针
}LinkQueue;          

//初始化——带头结点
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));  //队头队尾都指向头结点
    Q.front->next = NULL;
}
//初始化——不带头结点
void InitQueueWithoutHead(LinkQueue &Q)
{
    Q.front = Q.rear = NULL;     //队头队尾指向NULL
}

//判空——带头结点
bool IsEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}
//判空——不带头结点
bool IsEmptyWithoutHead(LinkQueue Q)
{
    return Q.front == NULL;
}

//入队——带头结点
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;   //建立链接
    Q.rear = s;
}
//入队——不带头结点
void EnQueueWithoutHead(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (IsEmptyWithoutHead(Q))
    {
        Q.front = s;
        Q.rear = s;
    }else{
        Q.rear->next = s;
        Q.rear = s;
    }
}

//出队——带头结点
bool OutQueue(LinkQueue &Q, ElemType &x)
{
    if (IsEmpty(Q))
    {
        return false;
    }
    LinkNode *s = Q.front->next;
    x = s->data;
    Q.front->next = s->next;

    if (Q.rear == s)            //若出队的已经是最后一个元素，修改头尾指针的位置
    {
        Q.rear==Q.front;
    }

    free(s);
    return true;
}

//出队——不带头结点
bool OutQueue(LinkQueue &Q, ElemType &x)
{
    if (IsEmptyWithoutHead(Q))
    {
        return false;
    }
    LinkNode *s = Q.front;
    x = s->data;
    Q.front = s->next;

    if (Q.rear == s)   //若出队列的已经是最后一个元素，将队恢复为空队的状态
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    
    free(s);
    return true;
}