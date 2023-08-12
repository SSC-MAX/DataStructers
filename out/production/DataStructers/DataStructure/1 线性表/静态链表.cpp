//
// Created by SC on 2022/1/22.
//

#include <stdio.h>

/*
 * 静态链表
 *  静态链表会分配一片连续的内存空间，使用数组来存储元素，每个数据元素包含自己的数值与下一项的下标（-1表示表尾）
 * */

#define MaxSize 10

struct Node{
    int data;
    int next;
}SLinkList[MaxSize];    //等同于 struct Node a[MaxSize],即定义一个数组，它的元素是Node

void initLinkList(int x)
{
    SLinkList[0].data = x;
    SLinkList[0].next = -1;
}




