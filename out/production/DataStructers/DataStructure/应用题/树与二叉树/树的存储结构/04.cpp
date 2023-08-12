#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{
    int data;
    BTNode *lChild, *rChild;
}BTNode, *BTree;

void visit(BTNode *node)
{
    if (node!=NULL)
    {
        visit(node->lChild);
        visit(node);
        visit(node->rChild);
    }
}

int LeafNode(BTree T) 
{
    if (T==NULL)
    {
        return 0;
    }
    if (T->lChild==NULL)
    {
        return 1+LeafNode(T->rChild);
    }else{
        return LeafNode(T->lChild)+LeafNode(T->rChild);
    }
}
