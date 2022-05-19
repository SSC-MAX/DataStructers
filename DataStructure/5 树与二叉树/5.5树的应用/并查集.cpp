#include <stdio.h>
#include <stdlib.h>

/*
    并查集
        使用双亲表示法将parent组成数组S
        查找：输入UFSet下标x，不断查找它的parent，直到parent为0，此时查找到根结点
        合并：输入UFSet下标x，将它parent数组的下标修改为要合并到的树的根结点
*/

#define SIZE 100
typedef struct BTNode
{
    int data;
    int parent;
}BTNode;

BTNode UFSet[SIZE];   // 包含了元素的并查集
int S[];       //存储parent

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
}

//找到位置在x的元素的根结点, 时间复杂度O(n)
int Find(int S[], int x)
{
    while (S[x] > 0)
    {
        x = S[x];
    }
    return x;
}

//合并  root1,root2指UFSet数组下标
void Union(int S[], int root1, int root2)
{
    if (root1 == root2)
    {
        return;
    }
    S[root2] = root1;
}
//并的优化算法,树的高度不会超过log(2)n + 1,此时查找的时间复杂度也会变为O(log(2)n)
void UnionPlus(int S[], int root1, int root2)
{
    if(root1==root2)
        return;
    if (S[root2]>S[root1]) //root1的树更高
    {
        S[root1] += S[root2];  //加入了新的元素，需要更新数组元素的数量
        S[root2] = root1;
    }else
    {
        S[root2] += S[root1];
        S[root1] = root2;
    }   
}
