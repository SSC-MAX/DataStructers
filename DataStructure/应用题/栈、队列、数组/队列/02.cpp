#include <stdio.h>
#define length 10

typedef struct 
{
    int data[length];
    int top = 0;
}Stack;

typedef struct 
{
    int data[length];
    int front, rear;
}Queue;

void reverseQueue(Queue &Q, Stack S)
{
    int i;
    for (i = 0; i < length; i++)
    {
        S.data[S.top] = Q.data[Q.front];
        Q.front = (Q.front+1)%length;
        S.top += 1;
    }
    for (i = 0; i < length; i++)
    {
        Q.data[Q.rear] = S.data[S.top];
        Q.rear = (Q.rear+1)%length;
        S.top -= 1;
    }
}

