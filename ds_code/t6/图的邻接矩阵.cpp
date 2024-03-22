#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

/*���ݴ洢��װ*/

//��󶥵���Ŀ
#define  MAX_VERTEX_NUM  50

typedef char VertexType;

//�ڽӾ���洢
typedef struct
{
    int vernum, arcnum;  //������������
    VertexType vertex[MAX_VERTEX_NUM];                 //������Ϣ
    int  edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];          //����Ϣ
}MGraph;

//==========================����ͼ====================================
//�ڽӾ��󴴽�����ͼ
void CreateMGraph(MGraph* G) {
    int i, j, k;
    char ch1, ch2;
    printf("�����붥����:");
    scanf("%d", &G->vernum);
    printf("���������:");
    scanf("%d", &G->arcnum);
    printf("�������������Ϣ(ÿ�������Իس�����):\n");
    for (i = 0; i < G->vernum; i++) {
        getchar();  //��ջ�����
        printf("�����%d����:", i + 1);
        scanf("%c", &(G->vertex[i]));
    }
    //������������Ϊ0
    for (i = 0; i < G->vernum; i++)
        for (j = 0; j < G->vernum; j++)
            G->edge[i][j] = 0;
    //��������Ϣ
    for (k = 0; k < G->arcnum; k++) {
        getchar();
        printf("�������Ϣ(�����ʽ:����1->����2):\n");
        scanf("%c->%c", &ch1, &ch2);
        for (i = 0; i < G->vernum; i++)
            for (j = 0; j < G->vernum; j++) {
                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //�Ƚ϶�������������ݺ��û���������ݣ�һ���������Ϊ1
                    G->edge[i][j] = 1;    //����ͼ
                }
            }
    }
}
//��ʾ����ͼ���ڽӾ���
void DisplayMGraph(MGraph G) {
    int i, j;
    printf("ͼ���ڽӾ���Ϊ:\n");
    for (i = 0; i < G.vernum; i++) {
        for (j = 0; j < G.vernum; j++)
            printf("%5d", G.edge[i][j]);
        printf("\n\n");
    }
}
//�������ͼ���еı�
void DisplayAllEdge(MGraph G) {
    printf("�������ͼ���еı�:\n");
    for (int i = 0; i < G.vernum; i++) {
        printf("���%c���ڵı�:\t",G.vertex[i]);
        for (int j = 0; j < G.vernum; j++) {
            if (G.edge[i][j] == 1) {
                printf("%c->%c\t",G.vertex[i],G.vertex[j]);
            }
        }
        printf("\n\n");
    }
}
//��������ͼ��������Ƿ����
void EdgeExist(MGraph G) {
    char vertex1, vertex2;
    getchar();
    printf("����Ҫ���ҵı�(eg. A->B):\n");
    scanf("%c->%c", &vertex1, &vertex2);
    //���Ҷ����±�
    int idx1=-1,idx2=-1;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex1)
            idx1 = idx;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex2)
            idx2 = idx;
            
    if(idx1== -1 || idx2 == -1)
        printf("�����������\n");
    else
    {
        printf("\n��ѯ���Ϊ:\n");
        if (G.edge[idx1][idx2] == 1)
                printf("%c��%c�ıߴ���\n", vertex1, vertex2);
        else
                printf("%c��%cû�б�\n",vertex1,vertex2);    
        printf("\n\n");
    }
}

//==========================����ͼ====================================
//�ڽӾ��󴴽�����ͼ
void CreateMGraph1(MGraph* G) {
    int i, j, k;
    char ch1, ch2;
    printf("�����붥����:");
    scanf("%d", &G->vernum);
    printf("���������:");
    scanf("%d", &G->arcnum);
    printf("�������������Ϣ(ÿ�������Իس�����):\n");
    for (i = 0; i < G->vernum; i++) {
        getchar();  //��ջ�����
        printf("�����%d����:", i + 1);
        scanf("%c", &(G->vertex[i]));
    }
    //������������Ϊ0
    for (i = 0; i < G->vernum; i++)
        for (j = 0; j < G->vernum; j++)
            G->edge[i][j] = 0;
    //��������Ϣ
    for (k = 0; k < G->arcnum; k++) {
        getchar();
        printf("�������Ϣ(�����ʽ:����1-����2):\n");
        scanf("%c-%c", &ch1, &ch2);
        for (i = 0; i < G->vernum; i++)
            for (j = 0; j < G->vernum; j++) {
                if (ch1 == G->vertex[i] && ch2 == G->vertex[j]) {        //�ԳƷ�λ��Ϊ1
                    G->edge[i][j] = 1;    //����ͼ
                    G->edge[j][i] = 1;    //����ͼ
                }
            }
    }
}
//��ʾ����ͼ���ڽӾ���
void DisplayMGraph1(MGraph G) {
    int i, j;
    printf("ͼ���ڽӾ���Ϊ:\n");
    for (i = 0; i < G.vernum; i++) {
        for (j = 0; j < G.vernum; j++)
            printf("%5d", G.edge[i][j]);
        printf("\n\n");
    }
}
//�������ͼ���еı�
void DisplayAllEdge1(MGraph G) {
    printf("�������ͼ���еı�:\n");
    for (int i = 0; i < G.vernum; i++) {
        printf("���%c���ڵı�:\t", G.vertex[i]);
        for (int j = 0; j < G.vernum; j++) {
            if (G.edge[i][j] == 1) {
                printf("%c-%c\t", G.vertex[i], G.vertex[j]);
            }
        }
        printf("\n\n");
    }
}
//��������ͼ��������Ƿ����
void EdgeExist1(MGraph G) {
    char vertex1, vertex2;
    getchar();
    printf("����Ҫ���ҵı�(eg. A-B):\n");
    scanf("%c-%c", &vertex1, &vertex2);
    //���Ҷ����±�
    int idx1 = -1, idx2 = -1;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex1)
            idx1 = idx;
    for (int idx = 0; idx < G.vernum; idx++)
        if (G.vertex[idx] == vertex2)
            idx2 = idx;

    if (idx1 == -1 || idx2 == -1)
        printf("�����������\n");
    else
    {
        printf("\n��ѯ���Ϊ:\n");
        if (G.edge[idx1][idx2]  == 1)
            printf("%c��%c�ıߴ���\n", vertex1, vertex2);
        else
            printf("%c��%cû�б�\n", vertex1, vertex2);
        printf("\n\n");
    }
}

int main() {
    MGraph G,G1;
    int choose;
    printf("==============���ڽӾ���洢ͼ��==============\n");
    printf("\n1:��������ͼ���ڽӾ���洢");
    printf("\n2:��������ͼ���ڽӾ���洢");
    printf("\n0:�˳�����\n\n");
    while (1) {
        scanf("%d", &choose);
        switch (choose)
        {
        case 1: {
            printf("����ͼ���ڽӾ���洢\n");
            CreateMGraph(&G);
            while (1) {
                printf("\n==============������ѡ�==============\n");
                printf("\n1:����ڽӾ���");
                printf("\n2:������еı�");
                printf("\n3:���ұ��Ƿ����");
                printf("\n0:�˳�����\n\n");
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
                    printf("\n�˳�����\n");
                    exit(1);
                    break;
                default:
                    printf("\n�������\n\n");
                    break;
                }
            }
            break; }
        case 2: {
            printf("����ͼ���ڽӾ���洢\n");
            CreateMGraph1(&G1);
            while (1) {
                printf("\n==============������ѡ�==============\n");
                printf("\n1:����ڽӾ���");
                printf("\n2:������еı�");
                printf("\n3:���ұ��Ƿ����");
                printf("\n0:�˳�����\n\n");
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
                    printf("\n�˳�����\n");
                    exit(1);
                    break;
                default:
                    printf("\n�������\n\n");
                    break;
                }
            }
            break; }
        case 0:
            printf("\n�˳�����\n");
            exit(1);
            break;
        default:
            printf("\n�������\n\n");
            break;
        }
    }
}
