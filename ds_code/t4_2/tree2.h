#define _CRT_SECURE_NO_DEPRECATE 
#include "tree2.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

// �������봴��������
Status CreateBiTree(BiTree& T) {
	char ch;
	scanf("%c", &ch);
	// �ո��ʾ�գ��ӣ���
	if (ch == ' ') T = NULL;
	else {
		// �����ڵ�
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;
		// ����
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

//���������ȡ
void PreOrderTraverse(BiTree T) {
	if (T == NULL) return;
	cout << T->data << ' ';
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//���������ȡ
void InOrderTraverse(BiTree T) {
	if (T == NULL) return;
	InOrderTraverse(T->lchild);
	cout << T->data << ' ';
	InOrderTraverse(T->rchild);
}

//���������ȡ
void PostOrderTraverse(BiTree T) {
	if (T == NULL) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << ' ';
}