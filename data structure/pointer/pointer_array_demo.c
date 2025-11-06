/*
 * 文件名: pointer_array_demo.c
 * 描述: 演示C语言中指针与数组的关系，包括整型数组和字符数组的
 *       静态分配、动态分配及指针数组的使用方法
 * 作者: [你的名字]
 * 创建日期: [日期]
 * 版本: 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int size = 10;

    int arr[10]; 
    // 定义一个固定大小为10的整数数组（在栈上分配）

    int *point = (int*) malloc(sizeof(int) * size);
    // 使用malloc在堆内存中开辟一个连续空间，大小为sizeof(int)*size字节
    // 用整型指针point指向首地址，可以像数组一样操作这10个整数
    // 注意：malloc分配的内存内容是未初始化的（可能是垃圾值）

    int *p[10] = {NULL};
    p[0] = (int*) malloc(sizeof(int) * size);
    // 定义了一个包含10个整型指针的数组，初始化为NULL
    // 将第一个指针指向一个动态分配的整数数组
    // 这样可以用p[0]操作第一个数组，p[1]操作第二个数组...实现用十个指针操作十个数组

    char c[] = "Jack";
    // 定义并初始化一个字符数组，编译器会自动计算大小为5（包含结尾的'\0'）
    // 实际上等价于：char c[5] = {'J','a','c','k','\0'};

    char *str = (char*) malloc(sizeof(char) * 5);  // 修正：应该是5，不是4
    strcpy(str, "Jack");
    // 用malloc开辟大小为5字节的连续空间（4个字符+1个终止符）
    // 字符指针str指向第一个字符的地址
    // 用strcpy将字符串"Jack"（包括终止符）复制到分配的内存中

    char *str_arr[4] = {NULL};
    str_arr[0] = (char*) malloc(sizeof(char) * 5);  // 修正：应该是5，不是4
    strcpy(str_arr[0], "Jack");
    // 定义了一个包含4个字符指针的数组，初始化为NULL
    // 将第一个指针指向一个动态分配的字符数组
    // 这样可以用四个指针操作四个不同的字符串

    // ============ 重要补充：内存释放 ============
    // 使用完动态分配的内存后必须释放，避免内存泄漏
    free(point);
    free(p[0]);
    free(str);
    free(str_arr[0]);
    
    return 0;
}