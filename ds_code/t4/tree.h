#pragma once

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//���Һ���ָ�� 
}BiTNode, * BiTree;

// �������봴��������
bool createBiTree(BiTree& T);
//���������ȡ
void preOrder(BiTree T);
//���������ȡ
void inOrder(BiTree T);
//���������ȡ
void postOrder(BiTree T);