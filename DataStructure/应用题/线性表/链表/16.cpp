#include "LinkList.h"

bool ifSon(LinkList A, LinkList B)
{
    LNode *p1 = A->next, *p2 = B->next, *s=p1;
    while (p1!=NULL && p2!=NULL)
    {
       if (p1->data == p2->data)
       {
           p1 = p1->next;
           p2 = p2->next;
       }else{
           s = s->next;
           p1 = s;
           p2 = B->next;
       }
    }
    if (p2==NULL)
    {
        return true;
    }else{
        return false;
    }
}