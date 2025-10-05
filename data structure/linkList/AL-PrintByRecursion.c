#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//递归法实现打印链表
void Print(struct Node *p)
{   
    if(p == NULL) 
    {
        return;
    }
    printf("%d ",p->data);
    Print(p->next);
}
