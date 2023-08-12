#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    char data;
    LNode *next;
}LNode, *LinkList;


bool testSy(LinkList &L)
{
    LNode *p=L, *r = L;
    char *c;
    int index = 0;
    while (r->next == NULL)
    {
        p = p->next;
        c[index] = p->data;
        index += 1;
        r = r->next;
        if (r->next!= NULL)
        {
            r = r->next;
        }
    }    //此时，p在中点，r在末尾
    p = p->next;
    for (int i = index-1; i >= 0; i--)
    {
        if (c[i] != p->data)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode* node1 = (LNode*)malloc(sizeof(LNode));
    L->next = node1;
    node1->data='x';
    
    LNode* node2 = (LNode*)malloc(sizeof(LNode));
    node1->next= node2;
    node2->data = 'y';

    LNode* node3 = (LNode*)malloc(sizeof(LNode));
    node2->next = node3;
    node3->data = 'y';

    LNode* node4 = (LNode*)malloc(sizeof(LNode));
    node3->next = node4;
    node4->data = 'x';

    if(testSy(L))
    {
        printf("正确");
    }else{
        printf("错误");
    }

    return 0;
}