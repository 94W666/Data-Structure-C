#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

//任意位置插入元素
void Insert(int data,int pos)
{
    /*
        逻辑实现：（便于理解，将节点的内存地址等效于链表中的次序）假设我们需要在第三个和第四个节点插入新的n节点，我们定义为x节点和y节点，我们只需要将x的next赋值为n的地址，将n的next赋值为y的地址
            即x->next = &n;n->next = &y;因此除了一个新的临时节点temp1外，我们还要引入一个可移动的struct Node指针temp2,让它移动到需要插入的位置
            那么循环多少次呢？我们知道，temp2是从第一个节点开始移动的，也就是temp2的初始值我们赋的是head，即它指向地址1，而根据上面的逻辑，只需要让它移动到位置3即可，也就是1+1+1；所以循环执行2次即可
            也就是for(int i = 0;i < 4 - 2;i++);执行了i=0，i=1这两次。
    */
   struct Node *temp1 = (struct Node*) malloc(sizeof(struct Node));
   struct Node *temp2 = head;
   temp1->data = data;
   temp1->next = NULL;

   if(pos == 1)
   {
    temp1->next = head;
    head = temp1;
    return;
   }

   for(int i = 0;i < pos - 2;i++)
   {
        temp2 = temp2->next;
   }
   //顺序一定是先将新节点的next设置为它想插入那个位置上的原节点地址
   temp1->next = temp2->next;
   temp2->next = temp1;
}
