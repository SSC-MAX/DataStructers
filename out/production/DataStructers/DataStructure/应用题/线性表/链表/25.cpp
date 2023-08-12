//
// Created by SC on 2022/1/26.
//

#include "LinkList.h"
/*
 * 单链表 L=(a1,a2,a3...an), 将其重新排序为 L=(a1,an,a2,an-1,a3,an-2...)
 *  步骤：
 *      1.将后半段链表翻转
 *      2.顺序依次插入
 * */


void reQueue(LinkList &L)
{
    LNode *p, *q, *r, *s;
    p=q=L;
    while (q->next!=NULL)
    {
        p = p->next;       //p走一步，q走两步，这样q到达末尾时p到达表的中点
        q = q->next;
        if (q->next!=NULL)
            q = q->next;
    }

    q=p->next;
    p->next = NULL;
    while (q!=NULL)
    {
        // 头插法将链表倒序
        r = q->next;
        q->next = p->next;
        p->next = q;

        q = r
    }

    s = L->next;
    q = p->next;
    p->next = NULL;
    while (q!=NULL)
    {
        // 头插法插入
        r = q->next;     // 使用r保存原q的下一个结点
        q->next = s->next; //头插
        s->next = q;
        s = q->next;    //q此时已成为s的后继，它的后继是s的原后继，也是s现在应该移动到的位置
        q = r;       //q回到原q的下一个结点，继续遍历
    }


}