#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data[10];
    struct node *left, *right;
}BTree;

void PrintExpression(BTree *T)
{
    VisitTree(T,1);
}

void VisitTree(BTree *root, int deep)
{
    if (root==NULL)
        return;
    if (root->left==NULL&&root->right==NULL)
    {
        printf("%s",root->data);
    }else
    {
        if (deep>1)
            printf("%s","(");
        VisitTree(root->left,deep+1);
        printf("%s",root->data);
        VisitTree(root->right,deep+1);
        if (deep>1)
            printf("%s",")");
    }
}