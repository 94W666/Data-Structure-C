#include <stdio.h>

#define V 5 //定义顶点数为5

typedef struct VNode
{
    int val;
    VNode *next;
}VNode;

VNode *adjList[V];  //定义了五个li
