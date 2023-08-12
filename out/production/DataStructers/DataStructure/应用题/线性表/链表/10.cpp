#include "LinkList.h"

void splitDataList(LinkList &L)
{
    LinkList B = (LNode*)malloc(sizeof(LNode));
    LNode *r=B,*s;
    LNode *p = L->next, *pre = L;;
    int count = 0;
    while (p != NULL)
    {
        count += 1;
        if (count%2==0)
        {
            s=(LNode*)malloc(sizeof(LNode));
            s->data = p->data;
            r->next = s;
            r = s;
            pre->next = p->next;
            free(p);
            p = pre->next;
            continue;
        }
        pre = p;
        p = p->next;
    }
    
}