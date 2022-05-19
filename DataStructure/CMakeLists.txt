cmake_minimum_required(VERSION 3.20)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)
add_executable(OrderList 一·线性表/顺序表.cpp)
add_executable(SingleLinkList 一·线性表/单链表.cpp)
add_executable(DoubleLinkList 一·线性表/双链表.cpp)
add_executable(CircleSingleLinkList 一·线性表/循环单链表.cpp)
add_executable(StaticLinkList 一·线性表/静态链表.cpp)

add_executable(QuickSort 八·排序/快速排序.cpp)

add_executable(CP19 应用题/线性表/链表/19.cpp)
add_executable(CD23 应用题/线性表/链表/23.cpp)
