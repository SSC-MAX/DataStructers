#include <stdio.h>

/*
*   二叉树的链式存储
    也称作二叉链表
    对于一棵有n个结点的二叉树，共会有2n个指针域，有n-1个结点都有父结点，所以共有n+1个结点
    若需要经常获取当前结点的父结点，可以增加一个父指针，成为三叉链表
*/

typedef struct BiNode
{
    int data;
    BiNode *lChild,*rChild;
}BiNode, *BiTree;
