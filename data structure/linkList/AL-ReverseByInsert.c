#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
struct Node *tempHead;

void InsertByTop(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = tempHead;
    tempHead = temp;
}
void Insert(int data)
{
    struct Node *temp1 = (struct Node*) malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next =NULL;
    struct Node *temp2;
    if(head == NULL)
    {
        head = temp1;
        temp2 = temp1;
        return;
    }
    temp2->next = temp1;
    temp2 = temp1;
}

//利用头插法实现反转链表
void Reverse()
{
    struct Node *pointer = head;
    while(pointer != NULL)
    {
        InsertByTop(pointer->data);
        pointer = pointer->next;
    }
    head = tempHead;
}
