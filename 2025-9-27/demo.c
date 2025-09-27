#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

void initSeqList(SeqList *L)
{
    L->length = 0;
}

int addElement(SeqList *L,ElemType e)
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

int main(void) 
{
   SeqList List;
   initSeqList(&List);

   printf("SeqList的长度为 %d\n",(&List)->length);

   addElement(&List,88);
   for(int i = 0;i < (&List)->length;i++)
   {
    printf("%d",(&List)->data[i]);
   }
   //这里的代码都有一个共同点，就是我想用 L->data 这种操作时，必须要加一个取地址符&，说明这种操作只能用在指针变量（即地址）上，而当我直接定义SeqList *List时，List 就是一个指针（地址）了，而*List共同一起才相当于普通变量
}
