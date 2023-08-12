//
// Created by SC on 2022/1/26.
//

#include "LinkList.h"

LNode* findElement(LinkList str1, LinkList str2)
{
    LNode *p1 = str1->next, *p2 = str2->next;
    int length1=0, length2=0;
    while (p1!=NULL)
    {
        length1 += 1;
        p1 = p1->next;
    }
    while (p2!=NULL)
    {
        length2 += 1;
        p2 = p2->next;
    }

    for (p1 = str1; length1 > length2 ; length1--) {
        p1 = p1->next;
    }
    for (p2=str2; length2 > length1; length2--){
        p2 = p2->next;
    }
    while (p1!=NULL&&p1!=p2)
    {
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}

