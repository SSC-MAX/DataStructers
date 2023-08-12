//
// Created by SC on 2022/1/20.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 快速排序
 *  效率：
 *      每一次都需要处理剩余的待排序元素，而这些元素的数量最大不超过n
 *          所以时间复杂度=O(n*递归层数),认为是O(nlog<2>n)
 *      每一次递归都需要开辟一片新的空间
 *          所以空间复杂度=O(递归层数）
 *      实质上将每一次划分的过程拆解可以得到一棵二叉排序树，二叉排序树的高度就是递归的层数
 *          对于有n个节点的二叉树，其高度最少为O(log<2>n),最多为n
 *          所以最好时间复杂度O(nlog<2>n)，最坏时间复杂度O(n^2)，不过平均时间复杂度更接近最好的情况
 *          递归的层数取决于划分后左右子数组的均衡程度，越均衡，递归层数越少，时间复杂度越低
 *          最好时，每次划分正好在中间
 *          最坏时，每次划分左右两边都很不均衡，如已经正序或倒序的数组，相当于选取了最小值或最大值作为pivot
 *          因此对快速排序的优化可以对左、中、右元素进行比较后选取一个作为pivot或随机选取一个元素作为pivot
 *   稳定性：
 *      不稳定，元素的位置可能发生变化
 *   注：
 *      408的定义中：
 *          一次划分指调用一次Partition，即进行一次划分，只可确定一个元素的最终位置
 *          一趟排序指对所有待排序元素进行一次处理，可能包含多次划分，也就可能确定多个元素的最终位置
 *              如第一趟对0-length进行处理，第二趟对0-pivot,pivot-length进行处理
 * */

int Partition(int* A, int low, int high)
{
    int pivot = A[low];
    while (low<high)
    {
        while (low<high && A[high]>pivot)   //high的作用在于找到第一个小于pivot的值
            high--;
        A[low] = A[high];   //找到了第一个小于pivot的值，将其与low交换位置
        while (low<high && A[low]<pivot)   // low的作用在于找到第一个大于pivot的值
            low++;
        A[high] = A[low];    //找到了第一个大于pivot的值，将其与high交换位置
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int* A, int low, int high)
{
    if (low<high)
    {
        int pivot = Partition(A,low,high);  //先对整个数组进行一次划分
        QuickSort(A,0,pivot-1);  // 对左子数组进行划分
        QuickSort(A,pivot+1,high);   // 对右子数组进行划分
    }
}

int cmp(const void *_a, const void *_b)
{
    int a = *(int*)_a, b=*(int*)_b;
    return b-a;
}

int main()
{
    int A[6] = {3,2,5,6,7,1};
    qsort(A,6, sizeof(int),cmp);

//    printf("排序\n");
//    QuickSort(A,0,5);


    for (int i : A) {
        printf("%d ",i);
    }
    return 0;
}

