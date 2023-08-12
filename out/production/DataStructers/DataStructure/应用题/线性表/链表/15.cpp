#include "LinkList.h"

void getCommon(LinkList &A, LinkList &B)
{
    LNode *pa = A->next, *pb = B->next,*s;
    A->next = NULL;
    while (pa!=NULL && pb!=NULL)
    {
        if (pa->data<pb->data)
        {
            pa = pa->next;
        }
        if (pb->data < pa->data)
        {
            pb = pb->next;
        }
        if (pa->data == pb->data)
        {
            s = pa->next;
            pa->next = A->next;
            A->next = pa;
            pa = s;
            s = pb;
            pb = pb->next;
            free(s);
        }
    }
    if (pb!=NULL)
    {
        pa = pb;
    }
    while (pa!=NULL)
    {
        s = pa;
        pa = pa->next;
        free(s);
    }
}