#include <stdio.h>

typedef struct BiNode
{
    int data;
    BiNode *lchild, *rchild;
}BiNode, *BiTree;

/*
    三种遍历仅根结点的遍历顺序不同
    时间复杂度:O(n) （每个结点都只访问一次）
    空间复杂度:O(n) （最坏情况下一层仅有一个结点，树的深度变为n,递归工作栈的深度为树的深度）
    中序+前序/后序/层次 可以得出二叉树完整的结构
    但是没有中序，只有前序、后序、层序无法得出唯一的二叉树的完整结构
*/

/*
    先序遍历的顺序：根-左-右
*/
void PreOrder(BiTree T)
{
    if (T!=NULL)
    {
        printf("%d ",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*
    中序遍历：左-根-右
*/
void InOrder(BiTree T)
{
    if (T!=NULL)
    {
        InOrder(T->lchild);
        printf("%d",T->data);
        InOrder(T->rchild);
    }
}

/*
    后序遍历：左-右-根
*/
void lastOrder(BiTree T)
{
    if (T!=NULL)
    {
        lastOrder(T->lchild);
        lastOrder(T->rchild);
        printf("%d",T->data);
    }
}
