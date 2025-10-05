#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Print()
{
    struct Node *temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}