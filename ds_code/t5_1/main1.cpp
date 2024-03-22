#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define FALSE 0
#define TRUE 1
#define ERROR 0
#define OVERFLOW -2
#define MAXQSIZE 100

typedef struct BiTNode{
    char data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

/* �㷨 
���������������һ����������CreateBiTree����Ȼ�󹹽�һ�����У����ø��ڵ���ӣ����׳��Ӳ����ʶ��׵����ӡ��Һ��ӣ�û�еĻ��á�#'���棩��
�����ӷ��ʵ�p������ʱ����p��ȫΪNULL���������Ϊ��ȫ��������*/
int CreateBiTree(BiTree& T)
{
    char c;
    scanf("%c", &c);
    if (c == '#') T = NULL;
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T) {
            printf("��ʼ������ʧ��");
            exit(1);
        }
        T->data = c;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return OK;
}
void  Judge(BiTree T)
{
    int	f = 0, r = 0, s = 0;
    BiTree p, q[MAXQSIZE];
    q[r++] = T;//�������� 
    while (f < r)
    {
        p = q[f++];//�������� 
        if (p)
        {
            q[r++] = p->lchild;//������� 
            q[r++] = p->rchild;//�Һ������ 
        }
        else
        {
            while (f < r)
            {
                p = q[f++];
                if (p)s++;
            }
        }
    }
    if (s != 0)
        printf("������������ȫ������\n");
    if (s == 0)
        printf("����������ȫ������\n");
}
int main(){
    BiTree T;
    printf("����������������Ľ�㣺\n");
    CreateBiTree(T);
    Judge(T);
    printf("\n");
    system("pause");
    return 0;
}
//ABC##DE##F###