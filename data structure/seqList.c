#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

//将int别命名为为ElemType
typedef int ElemType;

//定义一个顺序表结构体
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

void initSeqList(SeqList *L)
{
    L->length = 0;
}

//顺序表的添加元素-尾部添加法
int addEleme(SeqList *L,ElemType e)
{
    if(L->length >= MAXSIZE)
    {
        printf("顺序表已满 ");
        return 0;
    }

    L->data[L->length] = e;
    L->length++;
    return 1;
}

//顺序表的插入元素
int insertElem(SeqList *L,int pos,ElemType e)
{
    if(L->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入元素 \n");
        return 0;
    }

    if(pos <= L->length)
    {
        //因为数组的下标是从0开始的，所以真是的下标是长度或位置减去一
        for(int i = L->length-1;i >= pos-1;i--)
        {
            L->data[i+1] = L->data[i];
        }

        L->data[pos-1] = e;
        //长度更新
        L->length++;
    }
    return 1;
}

//顺序表的删除元素
int deleteElem(SeqList *L,int pos,ElemType *e)
{
    //一般情况下，用一个值接收被删除的那个值，为其他情况方便
    *e = L->data[pos-1];
    if(pos < L->length)
    {
        for(int i = pos;i <= L->length-1;i++)
        {
            L->data[i-1] = L->data[i];
        }
    }
    //直接人为的将长度减去1，不用管最后的那个值
    L->length--;
    return 1;
}

//顺序表的查找
int findElem(SeqList *L,ElemType *e)
{
    if(L->length == 0)
    {
        printf("空链表\n");
        return 0;
    }

    for(int i = 0;i < L->length;i++)
    {
        if(*e == L->data[i])
        {
            return i;
        }
    }
    return 0;
}

int main(void) 
{
   SeqList List;
   ElemType *e;
   initSeqList(&List);

   printf("初始化成功 SeqList的长度为 %d\n",(&List)->length);

   addEleme(&List,88);
   addEleme(&List,54);
   addEleme(&List,66);
   addEleme(&List,29);
   insertElem(&List,3,18);

   for(int i = 0;i < (&List)->length;i++)
   {
    printf("%d ",(&List)->data[i]);
   }
   //这里的代码都有一个共同点，就是我想用 L->data 这种操作时，必须要加一个取地址符&，说明这种操作只能用在指针变量（即地址）上，而当我直接定义SeqList *List时，List 就是一个指针（地址）了，而*List共同一起才相当于普通变量
   deleteElem(&List,2,e);

   printf("\n");

   for(int i = 0;i < (&List)->length;i++)
   {
    printf("%d ",(&List)->data[i]);
   }

   printf("\n");
   printf("%d",*e);
}
