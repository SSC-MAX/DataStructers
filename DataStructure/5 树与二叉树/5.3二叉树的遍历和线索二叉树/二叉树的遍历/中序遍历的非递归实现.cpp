#include <stdio.h>
#include <stdlib.h>

/*
*   中序遍历的非递归实现
    使用栈来解决递归的情况：
        1.若当前结点非空，就入栈，并检查其左子结点是否为空
        2.若当前结点为空，出栈栈顶结点，并转而开始检查栈顶结点的右子树
*/
typedef struct BiNode
{
    
    int data;
    BiNode *lChild, *rChild;
}BiNode, *BiTree;

typedef struct StackNode
{
    BiNode *data;
    StackNode *next;
}*Stack;

void initStack(Stack &S)
{

    S->next = NULL;
}

bool isEmpty(Stack S)
{
    return S->next == NULL;
}

bool push(Stack &S, BiNode *p)
{
    StackNode* s = (StackNode*)malloc(sizeof(StackNode));
    s->data = p;
    s->next = S->next;
    S->next = s;
}

bool pop(Stack &S, BiNode *p)
{
    if (isEmpty(S))
    {
        return false;
    }
    StackNode *s = S->next;
    p = S->next->data;
    S->next = s->next;
    free(s);
}

void getTop(Stack &S, BiNode *&p)
{
    p = S->next->data;
}

//非递归中序遍历
void MidOrder(BiTree T)
{
    Stack S;
    BiNode *p = T;
    initStack(S);
    while (p!=NULL || !isEmpty(S))
    {
        if (p!=NULL)
        {
            push(S,p);
            p = p->lChild;
        }else
        {
            pop(S,p);
            printf("%d\n",p->data);
            p = p->rChild;
        }
    }
}

//非递归前序遍历
void preOrder(BiTree T)
{
    Stack S;
    initStack(S);
    BiNode *p = T;
    while (p!=NULL || !isEmpty(S))
    {
        if (p!=NULL)
        {
            printf("%d\n",p->data);
            push(S,p);
            p=p->lChild;
        }else
        {
            pop(S,p);
            p = p->rChild;
        }
    }
}

//非递归后续遍历
void lastOrder(BiTree T)
{
    Stack S;
    initStack(S);
    BiNode *p = T;
    BiNode *r;
    while (p!=NULL || isEmpty(S))
    {
        if (p)
        {
            push(S,p);
            p = p->lChild;
        }
        else
        {
            getTop(S,p);
            if (p->rChild!=NULL&&p->rChild!=r)
            {
                p = p->rChild;
            }
            else
            {
                pop(S,p);
                printf("%d\n",p->data);
                r = p;
                p = NULL;
            }
            
        }
        
    }
    
}

int main()
{
    int a = 123;
    return 0;
}


