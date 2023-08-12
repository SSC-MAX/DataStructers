#include "LinkList.h"

void reversePrint(LinkList L)
{
    if (L->next!=NULL)
    {
        reversePrint(L->next);
    }
    if (L!=NULL)
    {
        printf("%d",L->data);
    }
}