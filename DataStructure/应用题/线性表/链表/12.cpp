#include "LinkList.h"

void unique(LinkList &L)
{
    LNode *pre = L->next, *p;
    while (pre->next!=NULL)
    {
        p = pre->next;
        while (pre->data == p->data)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        pre = pre->next;
    }
    
}