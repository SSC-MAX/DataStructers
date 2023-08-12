#include "LinkList.h"

int getLength(LinkList L)
{
    LNode *p = L->next;
    int count = 1;
    while (p!=NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}

LinkList searchCommon(LinkList &L1, LinkList &L2)
{
    int len1 = getLength(L1);
    int len2 = getLength(L2);
    LinkList longList, shortList;
    int distance;
    if (len1>len2)
    {
        longList = L1;
        shortList = L2;
        distance = len1-len2;
    }else{
        longList = L2;
        shortList = L1;
        distance = len2 - len1;
    }
    while (distance>0)
    {
        longList = longList->next;
        distance --;
    }
    while (longList!=NULL)
    {
        if (longList==shortList)
        {
            return longList;
        }else{
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}