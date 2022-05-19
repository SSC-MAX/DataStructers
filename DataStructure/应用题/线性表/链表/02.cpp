#include "LinkList.h"

void deleteNode(LinkList &L, int x)
{
    LNode *p = L;
    LNode *d;
    while (p->next!=NULL)
    {
        if (p->next->data==x)
        {
            d=p->next;
            p->next = d->next;
            free(d);
        }
        p = p->next;
    }
    printf("删除完成\n");
}

int main()
{
    LinkList L;
    initLinkList(L);
    deleteNode(L,2);
    printLinkList(L);
}