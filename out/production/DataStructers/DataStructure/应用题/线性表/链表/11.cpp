#include "LinkList.h"

void splieLinkList(LinkList hc)
{
    LNode *pre = hc, *p = hc->next;
    LNode *B = (LNode*)malloc(sizeof(LNode)),*r = B;
    int count = 0;
    while (p!=NULL)
    {
        count += 1;
        if (count%2==0)
        {
            pre->next = p->next;
            B->next = p;
            p->next = r;
            r = p;
            p = pre->next;
            continue;
        }
        pre = p;
        p = p->next;
    }
    
}