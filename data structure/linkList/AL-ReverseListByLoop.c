#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//迭代法实现反转链表
void Reverse()
{
    struct Node *pre,*current,*next;
    current = head;
    pre = NULL;
    next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
}
