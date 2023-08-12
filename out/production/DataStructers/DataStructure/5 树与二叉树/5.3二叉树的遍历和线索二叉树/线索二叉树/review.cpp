#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    int data;
    ThreadNode *lChild, *rChild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;
ThreadNode *pre;

void CreateThreadTree(ThreadTree T)
{
    pre = NULL;
    if (T!=NULL)
    {
        InOrder(T);
        if (T->rChild==NULL)
        {
            T->rtag=1;
        }
        
    }
    
}
void InOrder(ThreadTree T)
{
    while (T!=NULL)
    {
        InOrder(T->lChild);
        vist(T);
        InOrder(T->rChild);
    }
    
}
void vist(ThreadNode *p)
{
    if (p->lChild==NULL)
    {
        p->lChild = pre;
        p->ltag = 1;
    }
    if (pre->rChild==NULL&&pre!=NULL)
    {
        pre->rChild = p;
        pre->rtag = 1;
    }
    pre = p;
}

void PreOrder(ThreadTree T)
{
    while (T!=NULL)
    {
        FirstVist(T);
        if (T->ltag==0)
        {
            PreOrder(T->lChild);
        }
        FirstVist(T->rChild);
    }
    
}
void FirstVist(ThreadNode *p)
{
    if (p->lChild==NULL)
    {
        p->lChild = pre;
        p->ltag = 1;
    }
    if (pre->rChild==NULL&&pre!=NULL)
    {
        pre->rChild = p;
        pre->rtag = 1;
    }
    
    
}