#include "LinkList.h"

void createLinkList(LinkList &A, LinkList &B)
{
    LinkList C = (LNode*)malloc(sizeof(LNode));
    C->next = NULL;
    LNode *pa = A->next, *pb = B->next;
    while (pa!=NULL && pb!=NULL)
    {
        if (pa->data<pb->data)
        {
            pa = pa->next;
        }else if (pa->data > pb->data)
        {
            pb = pb->next;
        }else{
            LNode *s = (LNode*)malloc(sizeof(LNode));
            s->data = pa->data;
            s->next = C->next;
            C->next = s;
            pa = pa->next;
            pb = pb->next;
        }
        
        
    }
    
}