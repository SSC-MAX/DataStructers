#include "LinkList.h"

void reverLinkList(LinkList L)
{
    LNode *p = L->next;
    LNode *r = p->next;
    LNode *t = r->next;
    p->next = NULL;
    while (r!=NULL)
    {
        r->next = p;
        L->next = r;
        p = r;
        r = t;
        if (t!=NULL)
        {
            t = t->next;
        }
    }
    
}