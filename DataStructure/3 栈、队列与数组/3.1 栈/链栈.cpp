#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *LStack;

void initWithHead(LStack &S)
{
    S = (LNode*)malloc(sizeof(LNode));
    S->next = NULL;
}
void initWithoutHead(LStack &S, int x)
{
    S = (LNode*)malloc(sizeof(LNode));
    S->data = x;
    S->next = NULL;
}

bool isEmptyWithHead(LStack S)
{
    return S->next == NULL;
}
bool isEmptyWithoutHead(LStack S)
{
    return S == NULL;
}

void pushWithHead(LStack &S, int x)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = x;
    p->next = S->next;
    S->next = p;
}
void pushWithoutHead(LStack &S, int x)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = x;
    p->next = S;
    S = p;
}

bool popWithHead(LStack &S, int &x)
{
    if (isEmptyWithHead(S))
    {
        return false;
    }
    LNode *p = S->next;
    x = p->data;
    S->next = S->next->next;
    free(p);
    return true;
}
bool popWithoutHead(LStack &S, int &x)
{
    if (isEmptyWithoutHead(S))
    {
        return false;
    }
    LNode *p = S;
    x = p->data;
    S = S->next;
    free(p);
    return true;
}
