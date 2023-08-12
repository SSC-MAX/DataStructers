#include "LinkList.h"

void deleteMin(LinkList &L)
{
    LNode *p=L->next;
    LNode *pre, *s;
    int min = p->data;
    while (p->next!=NULL)
    {
        if (p->next->data<min)
        {
            min = p->next->data;
            pre = p;
            s = p->next;
        }
    }
    pre->next = s->next;
    free(s);
}