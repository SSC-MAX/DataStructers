#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, *LinkList;

typedef struct LNode_C
{
    char data;
    struct LNode_C* next;
}LNode_C, *LinkList_C;

typedef struct DLNode
{
    int data;
    int freq;
    struct DLNode *prior, *next;
}DLNode, *DLinkList;

void printLinkList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void printCharLinkList(LinkList_C L)
{
    LNode_C *p = L->next;
    while (p != NULL)
    {
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

void printDLinkList(DLinkList DL)
{
    DLNode *p = DL->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

void initLinkList(LinkList &L)
{
    printf("准备新建");
    int x;
    L=(LNode*) malloc(sizeof(LNode));
    L->data = -1000;
    L->next = NULL;
    LNode *p = L;
    LNode *r = L;
    printf("请输入:\n");
    scanf("%d",&x);
    while (x!=9999)
    {
        p=(LNode*)malloc(sizeof(LNode));
        p->next = NULL;
        p->data = x;
        r->next = p;
        r=p;
        printf("请输入:\n");
        scanf("%d",&x);
    }
    printf("---创建的单链表是:---\n");
    printLinkList(L);
}

void initCharLinkList(LinkList_C &L)
{
    printf("准备新建");
    char x;
    L=(LNode_C*) malloc(sizeof(LNode_C));
    L->data = '0';
    L->next = NULL;
    LNode_C *p = L;
    LNode_C *r = L;
    printf("请输入:\n");
    scanf("%c",&x);
    while (x!='0')
    {
        p=(LNode_C*)malloc(sizeof(LNode_C));
        p->next = NULL;
        p->data = x;
        r->next = p;
        r=p;
        printf("请输入:\n");
        scanf("%c",&x);
    }
    printf("---创建的单链表是:---\n");
    printCharLinkList(L);
}