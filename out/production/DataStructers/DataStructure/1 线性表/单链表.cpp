//
// Created by SC on 2022/1/21.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//头插法建立单链表——有头结点
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L=(LinkList) malloc(sizeof(LNode));  //头结点
    L->next = NULL;                     // 置为空表
    printf("请输入:\n");
    scanf("%d",&x);
    while (x!=9999)
    {
        s=(LNode*) malloc(sizeof (LNode));
        s->data=x;
        s->next = L->next;
        L->next = s;
        printf("请输入:\n");
        scanf("%d",&x);
    }
    return L;
}
//头插法建立单链表——无头结点
LinkList List_HeadInsertWithoutHead(LinkList &L)
{
    LNode *head,*s;
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = head;
        head = s;
        scanf("%d",&x);
    }
    return L;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *s,*r = L;    // s表示新结点的指针，r表示表尾指针
    L->next = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        s=(LinkList) malloc(sizeof(LNode));
        s->data=x;
        r->next = s;    //表尾的下一项指到新结点
        r=s;            //新结点成为表尾
        scanf("%d",x);
    }
    r->next = NULL;
    return L;
}

//按序号查找第i个结点
LNode *GetElem(LinkList L, int i)
{
    int j=1;
    LNode *p = L->next;
    if (i==0)       //输入0就返回头结点
        return L;
    if (i<1)       //既不是0又小于1即不合法
        return NULL;
    while (p&&j<i)    //p不为空且未到i
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找结点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p =L->next;
    while (p)
    {
        if (p->data==e)
            return p;
        p = p->next;
    }
    return NULL;
}

//将值为x的结点插入到链表的第i个位置——尾插
bool insertNode(LinkList &L, int x, int i)
{
    printf("在%d后插入元素：%d\n",i,x);
    LNode *p = GetElem(L,i);
    if (p!=NULL)
    {
        LNode *s = (LNode*) malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return true;
    }
    return false;
}

//将值为x的结点插入到链表的第i个位置——头插
bool insertNodeHead(LinkList &L, int x, int i)
{
    printf("在%d前插入元素：%d\n",i,x);
    LNode *p = GetElem(L,i);
    if (p!=NULL)
    {
        LNode *s = (LNode*) malloc(sizeof(LNode));
        s->data = p->data;
        p->data = x;
        s->next = p->next;
        p->next = s;
    }
    return false;
}

//删除第i个结点
bool deleteElement(LinkList &L, int i)
{
    if (i<1)
        return false;
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

//删除结点p
bool deleteNode(LinkList &L, LNode* p)
{
    LNode *s = L->next;     //从表头开始遍历，查找到p的前驱结点就删除
    while (s->next!=NULL)
    {
        if (s->next==p)    //s的后继就是p，执行删除
        {
            s->next = p->next;
            free(p);
            return true;
        }
        s = s->next;
    }
    return false;
}

//计算表长
int getListCount(LinkList L)
{
    int count = 0;
    while (L->next != NULL)
    {
        count += 1;
        L = L->next;
    }
    return count;
}

int getListCountWithoutHead(LinkList L)
{
    int count = 0;
    while (L!=NULL)
    {
        count+=1;
        L = L->next;
    }
    return count;
}

void viewList(LinkList L)
{
    printf("------打印单链表------\n");
    LNode *p = L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkList L;
    List_HeadInsert(L);
    viewList(L);
    int x;
    int i;
    printf("输入插入的值和位置:\n");
    insertNodeHead(L,8,1);
    viewList(L);
    return 0;
}
