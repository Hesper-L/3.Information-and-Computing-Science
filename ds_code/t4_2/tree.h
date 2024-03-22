#pragma once
#pragma once

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//���Һ���ָ�� 
}BiTNode, * BiTree;

typedef bool Status;
#define OK true;
#define ERROR false;

// �������봴��������
Status CreateBiTree(BiTree& T);
//���������ȡ
void PreOrderTraverse(BiTree T);
//���������ȡ
void InOrderTraverse(BiTree T);
//���������ȡ
void PostOrderTraverse(BiTree T);