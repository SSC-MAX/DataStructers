#include <stdio.h>

typedef struct 
{
    int data[10];
    int front,rear;
    int tag = 0;
}SQueue;

bool EnQueue(SQueue &Q, int x)
{
    if (Q.tag==1 && Q.front==Q.rear)
    {
        return false;
    }
    Q.tag = 1;
    Q.rear = (Q.rear+1)%10;
    Q.data[Q.rear] = x;
    return true;
}

bool DeQueue(SQueue &Q, int &x)
{
    if (Q.tag == 0 && Q.front==Q.rear)
    {
        return false;
    }
    Q.tag = 0;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%10;
    return true;
}