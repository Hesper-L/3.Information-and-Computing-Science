#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

/*数据存储封装*/

//最大顶点数目
#define  MAX_VERTEX_NUM  50

typedef char VertexType;

//邻接矩阵存储
typedef struct
{
    int vernum, arcnum;  //顶点数，弧长
    VertexType vertex[MAX_VERTEX_NUM];                 //顶点信息
    int  edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];          //边信息
}MGraph;

//==========================有向图====================================
//邻接矩阵创建有向图
void CreateMGraph(MGraph* G) {
    int i, j, k;
    char ch1, ch2;
    printf("请输入顶点数:");
    scanf("%d", &G->vernum);
    printf("请输入边数:");
    scanf("%d", &G->arcnum);
    printf("输入各个顶点信息(每个顶点以回车结束):\n");
    for (i = 0; i < G->vernum; i++) {
        getchar();  //清空缓冲区
        printf("输入第%d顶点:", i + 1);
        scanf("%c", &(G->vertex[i]));
    }
    //将矩阵数据置为0
    for (i = 0; i < G->vernum; i++)
        for (j = 0; j < G->vernum; j++)
            G->edge[i][j] = 0;
    //建立边信息
    for (k = 0; k < G->arcnum; k++) {
        getchar();
        printf("输入边信息(输入格式:顶点1->顶点2):\n");
        scanf("%c->%c", &ch1, &ch2);
        for (i = 0; i < G->vernum; i++)
            for (j = 0; j < G->vernum; j++) {
                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //比较顶点数组里的数据和用户输入的数据，一致则矩阵置为1
                    G->edge[i][j] = 1;    //有向图
                }
            }
    }
}
//显示有向图的邻接矩阵
void DisplayMGraph(MGraph G) {
    int i, j;
    printf("图的邻接矩阵为:\n");
    for (i = 0; i < G.vernum; i++) {
        for (j = 0; j < G.vernum; j++)
            printf("%5d", G.edge[i][j]);
        printf("\n\n");
    }
}
//输出有向图所有的边
void DisplayAllEdge(MGraph G) {
    printf("输出有向图所有的边:\n");
    for (int i = 0; i < G.vernum; i++) {
        printf("与点%c相邻的边:\t",G.vertex[i]);
        for (int j = 0; j < G.vernum; j++) {
            if (G.edge[i][j] == 1) {
                printf("%c->%c\t",G.vertex[i],G.vertex[j]);
            }
        }
        printf("\n\n");
    }
}
//查找有向图的任意边是否存在
void EdgeExist(MGraph G) {
    char vertex1, vertex2;
    getchar();
    printf("输入要查找的边(eg. A->B):\n");
    scanf("%c->%c", &vertex1, &vertex2);
    //查找顶点下标
    int idx1=-1,idx2=-1;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex1)
            idx1 = idx;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex2)
            idx2 = idx;
            
    if(idx1== -1 || idx2 == -1)
        printf("顶点输入错误！\n");
    else
    {
        printf("\n查询结果为:\n");
        if (G.edge[idx1][idx2] == 1)
                printf("%c到%c的边存在\n", vertex1, vertex2);
        else
                printf("%c到%c没有边\n",vertex1,vertex2);    
        printf("\n\n");
    }
}

//==========================无向图====================================
//邻接矩阵创建无向图
void CreateMGraph1(MGraph* G) {
    int i, j, k;
    char ch1, ch2;
    printf("请输入顶点数:");
    scanf("%d", &G->vernum);
    printf("请输入边数:");
    scanf("%d", &G->arcnum);
    printf("输入各个顶点信息(每个顶点以回车结束):\n");
    for (i = 0; i < G->vernum; i++) {
        getchar();  //清空缓冲区
        printf("输入第%d顶点:", i + 1);
        scanf("%c", &(G->vertex[i]));
    }
    //将矩阵数据置为0
    for (i = 0; i < G->vernum; i++)
        for (j = 0; j < G->vernum; j++)
            G->edge[i][j] = 0;
    //建立边信息
    for (k = 0; k < G->arcnum; k++) {
        getchar();
        printf("输入边信息(输入格式:顶点1-顶点2):\n");
        scanf("%c-%c", &ch1, &ch2);
        for (i = 0; i < G->vernum; i++)
            for (j = 0; j < G->vernum; j++) {
                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //对称方位置为1
                    G->edge[i][j] = 1;    //无向图
                    G->edge[j][i] = 1;    //无向图
                }
            }
    }
}
//显示无向图的邻接矩阵
void DisplayMGraph1(MGraph G) {
    int i, j;
    printf("图的邻接矩阵为:\n");
    for (i = 0; i < G.vernum; i++) {
        for (j = 0; j < G.vernum; j++)
            printf("%5d", G.edge[i][j]);
        printf("\n\n");
    }
}
//输出无向图所有的边
void DisplayAllEdge1(MGraph G) {
    printf("输出无向图所有的边:\n");
    for (int i = 0; i < G.vernum; i++) {
        printf("与点%c相邻的边:\t", G.vertex[i]);
        for (int j = 0; j < G.vernum; j++) {
            if (G.edge[i][j] == 1) {
                printf("%c-%c\t", G.vertex[i], G.vertex[j]);
            }
        }
        printf("\n\n");
    }
}
//查找无向图的任意边是否存在
void EdgeExist1(MGraph G) {
    char vertex1, vertex2;
    getchar();
    printf("输入要查找的边(eg. A-B):\n");
    scanf("%c-%c", &vertex1, &vertex2);
    //查找顶点下标
    int idx1 = -1, idx2 = -1;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex1)
            idx1 = idx;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex2)
            idx2 = idx;

    if (idx1 == -1 || idx2 == -1)
        printf("顶点输入错误！\n");
    else
    {
        printf("\n查询结果为:\n");
        if (G.edge[idx1][idx2]  == 1)
            printf("%c到%c的边存在\n", vertex1, vertex2);
        else
            printf("%c到%c没有边\n", vertex1, vertex2);
        printf("\n\n");
    }
}

int main() {
    MGraph G,G1;
    int choose;
    printf("==============【邻接矩阵存储图】==============\n");
    printf("\n1:进入有向图的邻接矩阵存储");
    printf("\n2:进入无向图的邻接矩阵存储");
    printf("\n0:退出程序\n\n");
    while (1) {
        scanf("%d", &choose);
        switch (choose)
        {
        case 1: {
            printf("有向图的邻接矩阵存储\n");
            CreateMGraph(&G);
            while (1) {
                printf("\n==============【功能选项】==============\n");
                printf("\n1:输出邻接矩阵");
                printf("\n2:输出所有的边");
                printf("\n3:查找边是否存在");
                printf("\n0:退出程序\n\n");
                scanf("%d", &choose);
                switch (choose) {
                case 1:
                    DisplayMGraph(G);
                    break;
                case 2:
                    DisplayAllEdge(G);
                    break;
                case 3:
                    EdgeExist(G);
                    break;
                case 0:
                    printf("\n退出程序\n");
                    exit(1);
                    break;
                default:
                    printf("\n输入错误\n\n");
                    break;
                }
            }
            break; }
        case 2: {
            printf("无向图的邻接矩阵存储\n");
            CreateMGraph1(&G1);
            while (1) {
                printf("\n==============【功能选项】==============\n");
                printf("\n1:输出邻接矩阵");
                printf("\n2:输出所有的边");
                printf("\n3:查找边是否存在");
                printf("\n0:退出程序\n\n");
                scanf("%d", &choose);
                switch (choose) {
                case 1:
                    DisplayMGraph1(G1);
                    break;
                case 2:
                    DisplayAllEdge1(G1);
                    break;
                case 3:
                    EdgeExist1(G1);
                    break;
                case 0:
                    printf("\n退出程序\n");
                    exit(1);
                    break;
                default:
                    printf("\n输入错误\n\n");
                    break;
                }
            }
            break; }
        case 0:
            printf("\n退出程序\n");
            exit(1);
            break;
        default:
            printf("\n输入错误\n\n");
            break;
        }
    }
}
