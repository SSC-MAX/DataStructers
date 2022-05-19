#include "LinkList.h"

void printMax(LinkList &head)
{
    LNode *p = head->next;
    LNode *max, *preMax;
    while (p != NULL)
    {
        max = p;
        preMax = head;
        while (p->next != NULL)
        {
            if (p->next->data > max->data)
            {
                preMax = p;
                max = p->next;
            }
            p = p->next;
        }
        printf("%d", max->data);
        preMax->next = max->next;
        free(max);
        p = head->next;
    }
    free(head);
}