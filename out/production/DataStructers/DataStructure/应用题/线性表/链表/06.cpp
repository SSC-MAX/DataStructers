#include "LinkList.h"

void sortLinkList(LinkList &L)
{
    LNode *s = L->next;
    LNode *pre = s;
    LNode *p = s->next;
    int x;
    while (p->next!=NULL)
    {
        if (pre->data < p->data)
        {
            x = pre->data;
            pre->data = p->data;
            p->data = x;
        }
        p = p->next;
        pre = pre->next;
    }
}