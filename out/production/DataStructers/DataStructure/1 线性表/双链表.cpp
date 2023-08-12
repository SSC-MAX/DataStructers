//
// Created by SC on 2022/1/21.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinkList;

//头插法
void insertNode(DLinkList &DL)
{
    DNode *p;
    int x;
    DL = (DLinkList) malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        p=(DLinkList) malloc(sizeof(DNode));
        p->data = x;
        p->next = DL->next;
        p->prior = DL;
        if (DL->next!=NULL)       //若头结点后还没有插入新的结点，就不要将它的前驱指向p
            DL->next->prior=p;
        DL->next = p;
        scanf("%d",&x);
    }
}

//尾插
void insertNodeTail(DLinkList &DL)
{
    DNode *p,*t;  //t表示末尾
    int x;
    DL = (DLinkList) malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prior = NULL;
    t = DL;
    scanf("%d",&x);
    while (x!=9999)
    {
        p=(DNode*) malloc(sizeof(DNode));
        p->data = x;
        t->next = p;
        p->prior = t;
        t = p;
        scanf("%d",&x);
    }
    t->next = NULL;
}

DNode* findElement(DLinkList DL, int i)
{
    if (i==0)
        return DL;
    if (i<1)
        return NULL;
    int j=1;
    DNode *p = DL->next;
    while (j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}

//删除
void deleteNode(DLinkList &DL, int i)
{
    DNode *t = findElement(DL,i);
    if (t!=NULL)
    {
        t->next->prior = t->prior;
        t->prior->next = t->next;
        free(t);
    }
}

