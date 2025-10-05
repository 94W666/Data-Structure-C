#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//任意位置链表元素的删除
void Delete(int pos)
{
    //一点感悟：由于链表中的每个节点都是通过前一个节点的next来获取的，因此，当我们需要对某一个节点做处理时，只需要到达它的前一个节点即可。同时也说明了头指针的重要性。
        //在链表在中，我们永远知道我后面结点的地址，用于不知道我前面节点的地址
    struct Node *temp1 = head;
    struct Node *temp2;

    if(pos == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    for(int i = 0;i < pos - 2;i++)
    {
        temp1 = temp1->next;
    }
    temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2); 
}
