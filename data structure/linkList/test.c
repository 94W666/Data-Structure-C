#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

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

void Print(struct Node *p)
{   
    if(p == NULL) 
    {
        return;
    }
    printf("%d ",p->data);
    Print(p->next);
}

int main(void)
{
    head = NULL;
    Insert(2);
    Insert(5);
    Insert(6);
    Insert(8);

    Reverse(head);
    Print(head);
}