//
// Created by SC on 2022/1/19.
//

#include <stdio.h>
#include <stdlib.h>
#define InitSize 100

typedef int ElemType;

//静态分配的方式
typedef struct {
    ElemType data[100]; // 静态数组（最开始就定死了长度,使用for循环初始化）
    int length;   //当前长度
} StaticSqList;
void InitList(StaticSqList &L)
{
    L.length = 0;
    for (int i = 0; i <100 ; ++i) {
        L.data[i] = 0;   //不赋初值可能会被遗留的脏数据影响
    }
}

/*
 * 动态分配的方式
 * */
typedef struct {
    ElemType* data;   //指向数组的第一个元素
    int MaxSize,length;
} SeqList;
void InitList(SeqList &L)
{
    L.data = (int*) malloc(InitSize*sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
}
//扩容(即开辟一片扩容后的区域，将data指向它，再把原数据搬移过去，释放原来的空间
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data=(int*) malloc((L.MaxSize+len)*sizeof(ElemType));
    for (int i = 0; i <L.length ; ++i) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
//在第i个位序插入 O(n)
void insertElementStatic(SeqList &L, int i, ElemType element)
{
    if (i<1||i>L.length)
        return;
    if (L.length>=L.MaxSize)
        return;
    for (int j = L.length; j >= i ; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = element;
    L.length+=1;
}
// 在第i个位序删除 O(n)
void deleteElement(SeqList &L, int i)
{
    if (i<1||i>L.length)
        return;
    for (int j = i-1; j <L.length ; j++) {
        L.data[i] = L.data[i+1];
    }
    L.length -= 1;
}
// 按值查找 O(n)
bool findElement(SeqList &L, ElemType element)
{
    for (int i = 0; i <L.length ; ++i) {
        if (L.data[i] == element)
            return true;
    }
    return false;
}
