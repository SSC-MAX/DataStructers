//
// Created by SC on 2022/1/26.
//

#include "LinkList.h"

int getLastK(LinkList list,int k)
{
    LNode *p=list->next;
    LNode *q = list->next;
    int count = 1;
    while (p->next!=NULL)
    {
        if (count==k)
        {
            q = q->next;
        } else{
            count += 1;
        }
        p = p->next;
    }
    if (count!=k)
    {
        return 0;
    } else{
        printf("%d",q->data);
        return 1;
    }
}
