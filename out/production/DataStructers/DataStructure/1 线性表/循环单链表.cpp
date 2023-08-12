//
// Created by SC on 2022/1/22.
//

#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode*) malloc(sizeof(LNode));
    if (L==NULL)     //内存不足，分配失败
        return false;
    L->next = L;   //下一个指向自己
    return true;
}

//判空
bool Empty(LinkList L)
{
    if (L->next == L)   //头指针下一个指向自己即为空
        return true;
    else
        return false;
}


