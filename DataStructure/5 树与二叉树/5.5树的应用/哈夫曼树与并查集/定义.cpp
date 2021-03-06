#include <stdio.h>

/*
    哈夫曼树
        1.定义
            权：给每个结点赋予的，带有一定意义的值
            结点的带权路径长度：从根结点到目标结点经过的边数 * 目标结点的权值
            树的带权路径长度(WPL)：树中所有叶子结点的带权路径之和
            对于所有拥有n个带权的叶子结点的树，WPL最小的树称为哈夫曼树，即最优二叉树
        2.构造
            （1）从给定的叶子结点集合中选出两个权最小作为兄弟，添加根结点r制造出一棵三个结点的二叉树
            （2）将选中的两个结点的权值相加作为r的权值，继续从集合中选择权值最小的两个(可以选择这棵树)重复步骤（1）
        3.性质
            对于n个带权的叶子结点组成的哈夫曼树：
                1.不存在度为1的结点
                2.一共有2n-1个结点
                3.权越小的结点离根结点越远
                4.以上构造的哈夫曼树不唯一，但WPL相同
                5.需要合并n-1次
    哈夫曼编码
        1.定义
            固定长度编码：每个字符使用相等长度的二进制位表示
            可变长度编码：允许使用不同长度的二进制位表示不同的字符
            前缀编码：没有一个编码是其他编码的前缀，如 10 01 110是，但 1 10 110不是
            (非前缀编码在解码时可能出现歧义)
            哈夫曼编码：字符集中每一个字符做为结点，字符出现的频率作为权，以此构建哈夫曼树
                      由于哈夫曼树不唯一，编码的形式也可能不唯一
*/