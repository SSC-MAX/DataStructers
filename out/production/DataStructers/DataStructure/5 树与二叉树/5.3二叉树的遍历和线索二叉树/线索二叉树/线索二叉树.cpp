#include <stdio.h>
#include <stdlib.h>
/*
*   普通二叉树存在的问题
        遍历时，只能从根节点开始访问，无法从中间某一个节点开始
        每个节点都只能找到它的子结点，无法找到它的父结点
        （前驱与后继指按中序遍历排列后元素的前驱与后继）
        为了找到结点p的前驱：
            1.需要从根结点开始再次中序遍历，
            2.每次记录当前访问结点为q，上一访问结点为pre
            3.当p与q重叠时，pre即为p的父结点
        同理，寻找后继时，当pre与p重叠，q即为p的后继
*   线索二叉树
        若一结点没有左子树，就将它的左子树指向它的前驱，若没有右子树，就将它的右子树指向它的后继
        依据进行线索化的序列不同，有前序/中序/后序线索二叉树三种
    为什么会出现循环：
        对于结点a，他的前驱的确定是p等于a时进行的，但是它的后继是当pre等于a，即访问a的下一个结点时确定的
        对于中序遍历，将a确定为a的左子树的前驱时，已经中序遍历过a的左子树的左子树，因此不会导致循环
        对于前序遍历，将a确定为a的左子树的前驱时，按照前序遍历的顺序，还未对a的左子树的左子树进行遍历，此时a的左子树已指向a，会导致循环
        对于后序遍历，将a确定为a的左子树的前驱时，已经到了对a的visit阶段，此时已经对a的左子树进行了处理，不会导致循环
*/

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lChild, *rChild;
    int ltag, rtag;      //ltag=0表示lChild真的是左子树，否则为前驱，rtag同理
}ThreadNode, *ThreadTree;

ThreadNode *pre = NULL;    //指向当前访问结点的前驱

//中序线索化
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T!=NULL)
    {
        InThread(T);
        if (pre->rChild!=NULL)   //对最后一个结点进行处理,因为默认的rtag默认是0
        {
            pre->rtag = 1;
        }
    }
}
void InThread(ThreadTree T)     //中序遍历
{
    if (T!=NULL)
    {
        InThread(T->lChild);
        visit(T);      //在每次访问的时候进行线索化的操作
        InThread(T->rChild);
    }
}
void visit(ThreadNode *q)
{
    if (q->lChild == NULL)    //左子树为空，将左子树指向前驱
    {
        q->lChild = pre;
        q->ltag = 1;
    }
    if (pre!=NULL&&pre->rChild==NULL)     //右子树为空，将右子树指向后继
    {
        pre->rChild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//前序线索化
void createPreTree(ThreadTree T)
{
    pre = NULL;
    if (T!=NULL)
    {
        preOrder(T);
        pre->rtag = 1;
    }
}
void preOrder(ThreadTree T)
{
    if (T!=NULL)
    {
        preVisit(T);
        /*
            若对当前结点进行了线索化，其左子结点将指向它的前驱（画图可见为父结点），若不加处理会导致循环访问
        */
        if (T->ltag==0)
            preOrder(T->lChild);
        preOrder(T->rChild);
    }
}
void preVisit(ThreadNode *q)
{
    if (q->lChild == NULL)
    {
        q->lChild = pre;
        q->ltag = 1;   
    }
    if (pre!=NULL && pre->rChild == NULL)
    {
        pre->rChild = q;
        pre->rtag = 1;
    }
    pre = q;
}

//后序线索化同理，但是它不会存在先序线索化那种循环的问题，因为访问到当前结点时，它的左右子树就已经处理过了