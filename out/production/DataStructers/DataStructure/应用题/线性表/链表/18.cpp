#include "LinkList.h"

void linkTwoList(LinkList &A, LinkList &B)
{
    LNode *p1 = A->next, *p2 = B->next, *r1, *r2;
    while (true)
    {
        p1 = p1->next;
        if (p1->next == A)
        {
            r1 = p1;
            break;
        }
    }
    while (true)
    {
        p2 = p2->next;
        if (p2->next == B)
        {
            r2 = p2;
            break;
        }
    }
    r1->next = B;
    r2->next = A;
}