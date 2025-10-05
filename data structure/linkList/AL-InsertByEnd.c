#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//尾插法
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

/*有返回值的尾插法
struct Node* Insert(struct Node *head,int data)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next =NULL;
    if(head == NULL)
    {
        head = temp;
    }else{
        struct Node *temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}
*/
