#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    int data;
    ThreadNode *lChild, *rChild;
    int ltag, rtag;
};

//找后继——右子树最左下角的结点
ThreadNode *LastNode(ThreadNode *p)   //找到中序遍历下第一个被访问到的结点
{
    while (p->ltag==0)
    {
        p = p->lChild;
    }
    return p;
}
ThreadNode *NextNode(ThreadNode *p)
{
    if (p->rtag==0)
    {
        return LastNode(p);
    }
    return p->rChild;
}
//使用找后继的方法实现非递归的中序遍历
void InOrder(ThreadNode *p)
{
    for (ThreadNode *q=LastNode(p); q!=NULL; q=LastNode(q))
    {
        printf("%d\n",q->data);
    }
}

//找前驱——左子树最右下角的结点
ThreadNode *LastRight(ThreadNode *p)
{
    while (p->rtag==0)
    {
        p=p->rChild;
    }
    return p;
}
ThreadNode *PreNode(ThreadNode *p)   //找到前驱
{
    if (p->ltag==0)    //若当前结点非叶子结点，就去找它左子树最右下角的结点
    {
        return LastRight(p->lChild);
    }
    return p->lChild;    //若当前结点为叶子结点，直接返回它的左子树
}
//依此可以实现逆向中序遍历
void RevInorder(ThreadNode *T)
{
    for (ThreadNode *p=LastRight(T); p!=NULL; p=PreNode(p))
    {
        printf("%d\n",p->data);
    }
}

/*
*   先序线索二叉树
*       寻找前驱
            1.若ltag==1:已被线索化，左子树指向即为先序前驱
            2.若ltag==0，未被线索化，由于只有指向子树的指针，而左右子树都不可能是其前驱，所以找不到先序前驱
*       寻找后继
            1.若rtag==1 : return rChild
            2.若rtag==0,未被线索化，必有右子树，但不确定是否有左子树
                （1）若有左子树：先序后继为左子树根结点，return lChild
                （2）若没有左子树，先序后继为右子树根结点，return rChild
*/
ThreadNode *LastNode(ThreadNode *p)
{
    if (p->lChild==NULL)
    {
        return p->rChild;
    }
    return p->lChild;
}
ThreadNode *FoundLast(ThreadNode *p)
{
    //未被线索化，需要判断是否有左子树
    if (p->rtag==0)
    {
        return LastNode(p);
    }
    //已被线索化，直接返回右子树指向的后继
    return p->rChild;
}

/*只有指向子树的指针时，无法找到某一个结点的前驱*/


/*
    后序线索二叉树
*   寻找前驱
        1.若ltag==1，已被线索化，前驱为左子树指向
        2.若ltag==0，未被线索化，必有左子树，但不一定有右子树
            （1）若存在右子树，后序前驱为右子树根结点
            （2）若不存在右子树，后序前驱为左子树根结点
*   寻找后继
        1.若rtag==1,已被线索化，后继为右子树指向
        2.若rtag==0,未被线索化，但由于只有指向子树的指针，左右子树都不可能是其后继，所以找不到后序后继

*/
//寻找前驱
void *PreNodeInLast(ThreadNode *p)
{
    //若不存在右子树，后序前驱为左子树根结点
    if (p->rChild!=NULL)
    {
        return p->lChild;
    }
    //若存在右子树，后序前驱为右子树根结点
    return p->rChild;
}
void *FindPre(ThreadNode *p)
{
    //未被线索化，需要判断右子树是否存在
    if (p->ltag==0)
    {
        return PreNodeInLast(p);
    }
    //已被线索化，直接返回右子树指向的前驱
    return p->lChild;
}
/*只有指向子树的指针时，无法确定后继*/