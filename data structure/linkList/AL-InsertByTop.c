#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//添加元素--头插法
void Insert(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;//为该节点的数据域赋值
    temp->next = head;
    /*
        两种情况：当头指针head为空时，也就是说链表为空时，temp->next = head = NULL;这个时候，temp就是我整个链表的第一个元素
                 当头指针head不为空,即它指向一片有效内存时，说明链表中已经有了元素（既含有数据域，也含有指针域的结构），这个时候head的值就是此时链表的第一个节点的地址
                    当我执行这个语句时，temp->next = head = 第一个元素的地址 这个时候就形成了temp插在原来第一个元素前的新链表
    */
    head = temp;//然后再将此时新的第一个元素的地址赋值给head
}
