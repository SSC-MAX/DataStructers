#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode
{
    int data;
    BiNode *lChild, *rChild;
}BiNode, *BiTree;


typedef struct StackNode
{
    BiNode *data;
    StackNode *next;
}StackNode, *LinkStack;

bool isEmpty(LinkStack L)
{
    return L->next==NULL;
}

void push(LinkStack L, BiNode *node)
{
    StackNode *p = (StackNode*)malloc(sizeof(StackNode));
    p->data = node;
    p->next = L->next;
    L->next = p;
}
void pop(LinkStack L, BiNode *&N)
{
    StackNode *s = L->next;
    N = s->data;
    L->next = s->next;
    free(s);
}

void inOrder(BiTree T)
{
    LinkStack L;
    L->next = (StackNode*)malloc(sizeof(StackNode));
    BiNode *p = T;
    while (p||!isEmpty(L))
    {
        if (p!=NULL)
        {
            push(L,p);
            p = p->lChild;
        }
        else
        {
            pop(L,p);
            printf("%d\n",p->data);
            p = p->rChild;
        }
    }
}

void preOrder(BiTree T)
{
    LinkStack L;
    L->next = (StackNode*)malloc(sizeof(StackNode));
    BiNode *p = T;
    while (p!=NULL||!isEmpty(L))
    {
        printf("%d\n",p->data);
        push(L,p);
        if (p->lChild!=NULL)
        {
            p = p->lChild;
        }
        else{
            pop(L,p);
            p = p->rChild;
        }
        
    }
    
}


