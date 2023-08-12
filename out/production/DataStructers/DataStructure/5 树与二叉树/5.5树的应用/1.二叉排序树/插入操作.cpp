#include <stdio.h>
#include <stdlib.h>

typedef struct BSNode
{
    int data;
    BSNode *lChild, *rChild;
}BSNode, *BTree;

void insertNode(BTree T, int key)
{
    BSNode *p,*pre = T;
    while (p!=NULL)
    {
        if (key < p->data)
        {
            pre = p;
            p = p->lChild;
        }else
        {
            pre = p;
            p = p->rChild;
        }
    }
    p = (BSNode*)malloc(sizeof(BSNode));
    p->data = key;
    p->lChild = p->rChild = NULL;
}
