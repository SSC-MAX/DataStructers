#include "LinkList.h"

void deleteMinElement(LinkList &L)
{
    LNode *p = L->next,*s,*r;
    int min;
    while (p!=NULL)
    {
        s = L;
        min = p->data;
        while (p->next!=NULL)
        {
            if (p->next->data < min)
            {
               min = p->next->data;
               s = p;
            }
            p = p->next;
        }
        r = s->next;
        s->next = s->next->next;
        free(r);
        p = L->next;
    }
    free(L);
}



int main()
{
    printf("你好\n");
    LinkList L;
    initLinkList(L);
    deleteMinElement(L);
    return 0;
}