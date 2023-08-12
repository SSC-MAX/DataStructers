#include "LinkList.h"

void deleteNode(LinkList &L, int min, int max)
{
    LNode *p = L->next;
    LNode *pre = L;
    while (p!=NULL)
    {
        if (min<L->data && L->data>max)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
    
}