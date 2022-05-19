#include "LinkList.h"

void mergeList(LinkList &A, LinkList &B)
{
    LNode *pa = A->next, *pb = B->next, *s;
    while (pa!=NULL && pb!=NULL)
    {
        if (pa->data <= pb->data)
        {
            s = pa->next;
            pa->next = A->next;
            A->next = pa;
            pa = s;
        }else{
            s = pb->next;
            pb->next = B->next;
            B->next = pb;
            pb = s;
        }
    }
    if (pb!=NULL)
    {
        pb = pa;
    }
    
    while (pa!=NULL)
    {
        s = pa->next;
        pa->next = A->next;
        A->next = pa;
        pa = s;
    }
    free(B);
    
    
}