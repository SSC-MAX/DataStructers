//
// Created by SC on 2022/1/26.
//

#include "LinkList.h"

void deleteElement(LinkList &L, int n)
{
    LNode *pre = L,*p=pre->next;
    int *arr,i;
    arr = (int*) malloc((n+1)* sizeof(int));
    for (int j = 0; j <n ; ++j) {
        arr[j] = 0;
    }
    while (p!=NULL)
    {
        if (p->data<0)
        {
            i = n-(p->data+n);
        } else{
            i = p->data;
        }
        if (arr[i]==0)
        {
            arr[i] = 1;
        } else{
            pre->next = p->next;
            free(p);
        }
        pre = pre->next;
        p = pre->next;
    }
}

