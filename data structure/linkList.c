#include <stdio.h>
#include <stdlib.h>

struct Node //这里的struct Node 整体构成一个数据类型的名字，相当于int 也就是说struct Node = int
{
    int data;
    struct Node *next;
};

struct Node *head;//这是定义的头指针，不充当节点的作用，仅仅只是为了存储地址

//添加元素--头插法
void Add(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;//为该节点的数据域赋值
    temp->next = head;
    /*
        两种情况：当头指针head为空时，也就是说链表为空时，temp->next = head = NULL;这个时候，temp就是我整个链表的第一个元素
                 当头指针head不为空,即它指向一片有效内存时，说明链表中已经有了元素（既含有数据域，也含有指针域的结构），这个时候head的值就是此时链表的第一个节点的地址
                    当我执行这个语句时，temp->next = head = 第一个元素的地址 这个时候就形成了temp插在原来第一个元素前的新链表
    */
    head = temp;//然后再将此时新的第一个元素的地址赋值给head
}

//遍历打印链表
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

int main(void)
{
    head = NULL;
    printf("How many numbers \n");
    int n,x;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("Enter the number \n");
        scanf("%d",&x);
        Add(x);
        Print();
    }

    Insert(7,3);
    Print();
}