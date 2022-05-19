#include <stdio.h>
#include <stdlib.h>

/*
    层次遍历
    按照树的层数从上到下从左到右一层一层地遍历树中的元素
    需要借助一个队列来实现：
        1.将根结点入队
        2.若队列非空，将队首元素出队，访问
        3.若当前根结点左子树非空，左子树根结点入队，右子树同理
*/

typedef struct BiNode
{
    int data;
    BiNode *lchild, *rchild;
}BiNode, *BiTree;

typedef struct LinkNode
{
    BiNode *node;
    struct LinkNode *next;
};
typedef struct LinkQueue
{
    LinkNode *front, *rear;
};

void InitQueue(LinkQueue Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.rear->next = NULL;
}

bool isEmpty(LinkQueue Q)
{
    return Q.front==Q.rear;
}

void EnQueue(LinkQueue &Q, BiNode* node)
{
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->node = node;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

void DeQueue(LinkQueue &Q, BiNode* &node)
{
    LinkNode *s = Q.front->next;
    node = s->node;
    Q.front->next = s->next;
    free(s);
}

void levelOrder(BiTree T, LinkQueue Q)
{
    InitQueue(Q);
    EnQueue(Q,T);
    BiNode *p;
    while (!isEmpty(Q))
    {
        DeQueue(Q,p);
        printf("%d\n",p->data);
        if (p->lchild!=NULL)
        {
            EnQueue(Q,p->lchild);
        }
        if (p->rchild!=NULL)
        {
            EnQueue(Q,p->rchild);
        }
    }
    
}