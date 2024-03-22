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

/* 算法 
先以先序遍历输入一个二叉树（CreateBiTree），然后构建一个队列，先让根节点入队，队首出队并访问队首的左孩子、右孩子（没有的话用’#'代替）。
当出队访问的p不存在时，若p后全为NULL，则二叉树为完全二叉树。*/
int CreateBiTree(BiTree& T)
{
    char c;
    scanf("%c", &c);
    if (c == '#') T = NULL;
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        if (!T) {
            printf("初始化变量失败");
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
    q[r++] = T;//根结点入队 
    while (f < r)
    {
        p = q[f++];//根结点出队 
        if (p)
        {
            q[r++] = p->lchild;//左孩子入队 
            q[r++] = p->rchild;//右孩子入队 
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
        printf("二叉树不是完全二叉树\n");
    if (s == 0)
        printf("二叉树是完全二叉树\n");
}
int main(){
    BiTree T;
    printf("请依次输入二叉树的结点：\n");
    CreateBiTree(T);
    Judge(T);
    printf("\n");
    system("pause");
    return 0;
}
//ABC##DE##F###