//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
//#pragma warning(disable : 6031)
//#include <stdio.h>
//#include <stdlib.h>
////#include "Graph.h"
//
///*���ݴ洢��װ*/
//
////��󶥵���Ŀ
//#define  MAX_VERTEX_NUM  100
//
//typedef char VertexType;
//
////�ڽӾ���洢
//typedef struct
//{
//    int vernum, arcnum;  //������������
//    VertexType vertex[MAX_VERTEX_NUM];                 //������Ϣ
//    int  edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];          //����Ϣ
//}MGraph;
//
//
////�ڽӱ�洢
///*�߱���*/
//typedef struct node {
//    int adjvex;             //�ڽӵ���
//    struct node* next;      //ָ����һ�ڽӵ��ָ����
//}EdgeNode;
///*�����ڵ�*/
//typedef struct vexnode {
//    VertexType data;        //�洢������
//    EdgeNode* firstedge;    //ָ��ĵ�һ���߽��
//}VHeadNode;
///*ͼ*/
//typedef struct
//{
//    int vernum, arcnum;  //������������
//    VHeadNode adjlist[MAX_VERTEX_NUM];
//}AdjList;
//
//
//
////�ڽӾ��󴴽�ͼ
//void CreateMGraph(MGraph* G) {
//    int i, j, k;
//    char ch1, ch2;
//    printf("�����붥������");
//    scanf("%d", &G->vernum);
//    printf("�����������");
//    scanf("%d", &G->arcnum);
//    printf("�������������Ϣ(ÿ�������Իس�����)��\n");
//    for (i = 0; i < G->vernum; i++) {
//        getchar();  //��ջ�����
//        printf("�����%d����:", i + 1);
//        scanf("%c", &(G->vertex[i]));
//    }
//    //������������Ϊ0
//    for (i = 0; i < G->vernum; i++)
//        for (j = 0; j < G->vernum; j++)
//            G->edge[i][j] = 0;
//
//    //��������Ϣ
//    for (k = 0; k < G->arcnum; k++) {
//        getchar();
//        printf("�������Ϣ(�����ʽ������1������2)��\n");
//        scanf("%c,%c", &ch1, &ch2);
//        for (i = 0; i < G->vernum; i++)
//            for (j = 0; j < G->vernum; j++) {
//                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //�Ƚ϶�������������ݺ��û���������ݣ�һ���������Ϊ1
//                    G->edge[i][j] = 1;    //�������
//                    // G->edge[i][j]=1; //�������
//                }
//            }
//    }
//}
//
////��ʾ�ڽӾ���
//void DisplayMGraph(MGraph G) {
//    int i, j;
//    printf("\nͼ���ڽӾ���Ϊ��\n");
//    for (i = 0; i < G.vernum; i++) {
//        for (j = 0; j < G.vernum; j++)
//            printf("%5d", G.edge[i][j]);
//        printf("\n");
//    }
//}
//
////�ڽӱ���ͼ(flag=0 ����ͼ��flag=1 ����ͼ)
//void CreateAdjGraph(AdjList* g, int flag) {
//    int i, j, k;
//    EdgeNode* p;
//    if (flag == 0)
//        printf("������һ������ͼ");
//    else
//        printf("����һ������ͼ");
//    printf("�����붥������");
//    scanf("%d", &g->vernum);
//    printf("�����������");
//    scanf("%d", &g->arcnum);
//    printf("�������������Ϣ(ÿ�������Իس�����)��\n");
//    for (i = 0; i < g->vernum; i++) {
//        getchar();  //��ջ�����
//        printf("�����%d����:\n", i + 1);
//        scanf("%c", &(g->adjlist[i].data));
//        g->adjlist[i].firstedge = NULL;   //��ı߱�ͷָ��Ϊ��
//    }
//    printf("\b������ߵ���Ϣ�������ʽΪ�����1�����2\n");
//    for (k = 0; k < g->arcnum; k++) {
//        printf("�������%d����\n", k);
//        //�����Ϊi�Ľ����뵽�ڽӱ���
//        scanf("%d,%d", &i, &j);
//        p = (EdgeNode*)malloc(sizeof(EdgeNode));
//        if (!p) {
//            printf("��ʼ������ʧ��");
//            exit(1);
//        }
//        p->adjvex = j;        //�ڽӵ����Ϊj
//        p->next = g->adjlist[i].firstedge;       //���½ڵ�p�嵽����vi�߱�ͷ
//        g->adjlist[i].firstedge = p;
//
//        //�����Ϊj�Ľ����ӵ��ڽӱ��У�����ͼ����Ҫ���
//        if (flag == 0) {
//            p = (EdgeNode*)malloc(sizeof(EdgeNode));
//            if (!p) {
//                printf("��ʼ������ʧ��");
//                exit(1);
//            }
//            p->adjvex = i;        //�ڽӵ����Ϊj
//            p->next = g->adjlist[j].firstedge;       //���½ڵ�p�嵽����vi�߱�ͷ
//            g->adjlist[j].firstedge = p;
//        }
//    }
//}
////��ʾ�ڽӱ�
//void DisplayAdjGraph(AdjList g) {
//    int i;
//    EdgeNode* p;
//    printf("\nͼ���ڽӱ��ʾ��\n");
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
////�˵���
//void menu() {
//    printf("=================\n");
//    printf("1.�ڽӾ���洢ͼ\n");
//    printf("2.�ڽӱ�洢ͼ\n");
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
//            printf("�ڽӾ���洢\n");
//            CreateMGraph(&G);
//            DisplayMGraph(G);
//            break;
//        case 2:
//            printf("�ڽӱ�洢\n");
//            printf("ѡ��ͼ������(1.����ͼ��0.����ͼ)\n");
//            scanf("%d", &flag);
//            CreateAdjGraph(&g, flag);
//            DisplayAdjGraph(g);
//            break;
//        default:
//            printf("�������\n");
//            break;
//        }
//    }
//}
