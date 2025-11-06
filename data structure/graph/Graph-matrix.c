#include <stdio.h>

#define MAX_VEX 6 //定义最大顶点数为6

typedef struct
{
    char vex[MAX_VEX];//定义了顶点集
    int arc[MAX_VEX][MAX_VEX];//定义了边表
}MGraph;

//初始化邻接表---利用嵌套循环将矩阵设置为0
void Graph_Init (MGraph *G)
{
    for(int i =0;i < MAX_VEX;i++)
        for(int j = 0;j < MAX_VEX;j++)
            {
                G->arc[i][j] = 0;
            }
}

//求顶点的度---对于无向图
int Graph_UD_D (MGraph *G,int vexIndex) //vexIndex的意思是行索引，表示从该顶点出发
{
    int d = 0;
    for(int i = 0;i < MAX_VEX;i++)
    {
        if(G->arc[vexIndex][i] != 0)
        {
            d = d + 1;
        }
    }
    return d;
}

/*以下是对于有向图而言*/
//求顶点的度
int Graph_D_D (MGraph *G,int vexIndex)
{
    int id = 0;
    int od = 0;
    int d = 0;//有向图顶点的度等于其出度＋入度

    //计算出度
    for(int i = 0;i < MAX_VEX;i++)
    {
        if(G->arc[vexIndex][i] != 0)
        {
            id = id + 1;
        }
    }

    //计算入度
    for(int i = 0;i < MAX_VEX;i++)
    {
        if(G->arc[i][vexIndex] != 0)
        {
            od = od + 1;
        }
    }

    d = id + od;

    return d;
}
