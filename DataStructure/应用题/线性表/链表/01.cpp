#include "LinkList.h"

void DeleteNode(LinkList &L, int x)
{
    if (L==NULL)
    {
        return;
    }
    if (L->data==x)
    {
        LNode *p = L;
        L = L->next;
        free(p);
        DeleteNode(L,x);
    }else{
        DeleteNode(L->next,x);
    }
}