//Stack - Linked List implementation
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top;

//顶部放入--头插法
void Push(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->next = top;
    top = temp;
}

//顶部取出
void Pop()
{
    struct Node *temp;
    if(top == NULL)
    {
        return;
    }
    temp = top;
    top = temp->next;
    free(temp);
}

//返回顶部节点地址
struct Node* Top()
{
    return top;
}

struct Node* isEmpty()
{
    if(top == NULL)
    {
        return top;
    }
    return top;
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
    
}

