//
// Created by SC on 2022/1/26.
//

#include "LinkList.h"

DLNode* Locate(DLinkList &L, int x)
{
    DLNode *p = L->next,*s,*q;
    while (p!=NULL)
    {
        if (p->data == x)
        {
            p->freq += 1;
            //取下p
            if (p->next!=NULL)
                p->next->prior = p->prior;
            p->prior->next = p->next;
            //寻找p的插入位置
            s = p->prior;
            while (s->freq <= p->freq && s!=L)
                s = s->prior;
            p->next = s->next;
            s->next->prior = p;
            s->next = p;
            p->prior = s;
        }
        p = p->next;
    }
    return p;
}
