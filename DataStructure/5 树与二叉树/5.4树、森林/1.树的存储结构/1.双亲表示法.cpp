#include <stdio.h>

/*
*   双亲表示法
        实际上是顺序存储的一种方式
        在每个结点中加入指向父结点的下标以便找到父结点
        树的定义中使用一个数组来保存所有的结点
        插入结点时可以不按照层序来插入
        查找父结点很方便，但是查找子树就很困难，需要从头开始遍历
*/

#define MAX_TREE_SIZE 100
//结点的定义
typedef struct 
{
    int data;
    int parent;    //父结点的数组下标
}PTNode;
//树的定义
typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];    //一个数组，用于保存所有的结点
    int n;                         //结点数
}PTree;

