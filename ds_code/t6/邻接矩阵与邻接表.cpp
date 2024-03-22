//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
//#pragma warning(disable : 6031)
//#include <stdio.h>
//#include <stdlib.h>
////#include "Graph.h"
//
///*数据存储封装*/
//
////最大顶点数目
//#define  MAX_VERTEX_NUM  100
//
//typedef char VertexType;
//
////邻接矩阵存储
//typedef struct
//{
//    int vernum, arcnum;  //顶点数，弧长
//    VertexType vertex[MAX_VERTEX_NUM];                 //顶点信息
//    int  edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];          //边信息
//}MGraph;
//
//
////邻接表存储
///*边表结点*/
//typedef struct node {
//    int adjvex;             //邻接点域
//    struct node* next;      //指向下一邻接点的指针域
//}EdgeNode;
///*顶点表节点*/
//typedef struct vexnode {
//    VertexType data;        //存储的数据
//    EdgeNode* firstedge;    //指向的第一条边结点
//}VHeadNode;
///*图*/
//typedef struct
//{
//    int vernum, arcnum;  //顶点数，弧长
//    VHeadNode adjlist[MAX_VERTEX_NUM];
//}AdjList;
//
//
//
////邻接矩阵创建图
//void CreateMGraph(MGraph* G) {
//    int i, j, k;
//    char ch1, ch2;
//    printf("请输入顶点数：");
//    scanf("%d", &G->vernum);
//    printf("请输入边数：");
//    scanf("%d", &G->arcnum);
//    printf("输入各个顶点信息(每个顶点以回车结束)：\n");
//    for (i = 0; i < G->vernum; i++) {
//        getchar();  //清空缓冲区
//        printf("输入第%d顶点:", i + 1);
//        scanf("%c", &(G->vertex[i]));
//    }
//    //将矩阵数据置为0
//    for (i = 0; i < G->vernum; i++)
//        for (j = 0; j < G->vernum; j++)
//            G->edge[i][j] = 0;
//
//    //建立边信息
//    for (k = 0; k < G->arcnum; k++) {
//        getchar();
//        printf("输入边信息(输入格式：顶点1，顶点2)：\n");
//        scanf("%c,%c", &ch1, &ch2);
//        for (i = 0; i < G->vernum; i++)
//            for (j = 0; j < G->vernum; j++) {
//                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //比较顶点数组里的数据和用户输入的数据，一致则矩阵置为1
//                    G->edge[i][j] = 1;    //有向矩阵
//                    // G->edge[i][j]=1; //无向矩阵
//                }
//            }
//    }
//}
//
////显示邻接矩阵
//void DisplayMGraph(MGraph G) {
//    int i, j;
//    printf("\n图的邻接矩阵为：\n");
//    for (i = 0; i < G.vernum; i++) {
//        for (j = 0; j < G.vernum; j++)
//            printf("%5d", G.edge[i][j]);
//        printf("\n");
//    }
//}
//
////邻接表创建图(flag=0 无向图，flag=1 有向图)
//void CreateAdjGraph(AdjList* g, int flag) {
//    int i, j, k;
//    EdgeNode* p;
//    if (flag == 0)
//        printf("将建立一个无向图");
//    else
//        printf("建立一个有向图");
//    printf("请输入顶点数：");
//    scanf("%d", &g->vernum);
//    printf("请输入边数：");
//    scanf("%d", &g->arcnum);
//    printf("输入各个顶点信息(每个顶点以回车结束)：\n");
//    for (i = 0; i < g->vernum; i++) {
//        getchar();  //清空缓冲区
//        printf("输入第%d顶点:\n", i + 1);
//        scanf("%c", &(g->adjlist[i].data));
//        g->adjlist[i].firstedge = NULL;   //点的边表头指针为空
//    }
//    printf("\b请输入边的信息，输入格式为：序号1，序号2\n");
//    for (k = 0; k < g->arcnum; k++) {
//        printf("请输入第%d条边\n", k);
//        //将编号为i的结点加入到邻接表中
//        scanf("%d,%d", &i, &j);
//        p = (EdgeNode*)malloc(sizeof(EdgeNode));
//        if (!p) {
//            printf("初始化变量失败");
//            exit(1);
//        }
//        p->adjvex = j;        //邻接点序号为j
//        p->next = g->adjlist[i].firstedge;       //将新节点p插到顶点vi边表头
//        g->adjlist[i].firstedge = p;
//
//        //将编号为j的结点添加到邻接表中，有向图不需要添加
//        if (flag == 0) {
//            p = (EdgeNode*)malloc(sizeof(EdgeNode));
//            if (!p) {
//                printf("初始化变量失败");
//                exit(1);
//            }
//            p->adjvex = i;        //邻接点序号为j
//            p->next = g->adjlist[j].firstedge;       //将新节点p插到顶点vi边表头
//            g->adjlist[j].firstedge = p;
//        }
//    }
//}
////显示邻接表
//void DisplayAdjGraph(AdjList g) {
//    int i;
//    EdgeNode* p;
//    printf("\n图的邻接表表示：\n");
//    for (i = 0; i < g.vernum; i++) {
//        printf("%2d[%c]", i, g.adjlist[i].data);
//        p = g.adjlist[i].firstedge;
//        while (p != NULL) {
//            printf("-->[%d]", p->adjvex);
//            p = p->next;
//        }
//        printf("\n");
//    }
//}
////菜单项
//void menu() {
//    printf("=================\n");
//    printf("1.邻接矩阵存储图\n");
//    printf("2.邻接表存储图\n");
//    printf("=================\n");
//
//}
//
//int main() {
//    MGraph G;
//    AdjList g;
//    int choose, flag;
//    menu();
//    while (1) {
//        scanf("%d", &choose);
//        switch (choose)
//        {
//        case 1:
//            printf("邻接矩阵存储\n");
//            CreateMGraph(&G);
//            DisplayMGraph(G);
//            break;
//        case 2:
//            printf("邻接表存储\n");
//            printf("选择图的类型(1.有向图，0.无向图)\n");
//            scanf("%d", &flag);
//            CreateAdjGraph(&g, flag);
//            DisplayAdjGraph(g);
//            break;
//        default:
//            printf("输入错误\n");
//            break;
//        }
//    }
//}
