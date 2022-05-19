#include <stdio.h>

/*
*   孩子表示法（链式+顺序）
        对于一个结点，将它的所有孩子结点串成一个链表，链表的第一个元素的指针保存在当前结点的结构体中
        同样的，很容易找到孩子，但是很难找到双亲
*/
#define MAX_TREE_SIZE 100

//由孩子结点组成的链表的定义
struct CTNode
{
    int n;   //孩子结点在数组中的位置
    struct CTNode *next;
};
//单个结点的定义
typedef struct 
{
    int data;
    struct CTNode *firstChild;
}CTBox;
//树的定义
typedef struct 
{
    CTBox nodes[MAX_TREE_SIZE];
    int n;
};


