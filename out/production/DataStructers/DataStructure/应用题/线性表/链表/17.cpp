#include "LinkList.h"

bool ifSy(DLinkList L)
{
    DLNode *r = L->prior,*p = L->next;
    if (r==p)
    {
        return false;
    }
    while (r->data == p->data && r!=L)
    {
        r = r->prior;
        p = p->next;
    }
    if (r==p)
    {
        return true;
    }
    return false;
    
    
    
}