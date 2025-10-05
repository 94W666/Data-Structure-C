#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//递归法实现反转链表
void Reverse(struct Node *current)
{
    if(current->next == NULL)
    {
        head = current;
        return;
    }
    Reverse(current->next);
    struct Node *next = current->next;
    next->next = current;
    current->next = NULL;
}