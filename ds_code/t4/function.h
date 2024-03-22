#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "tree.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

bool createBiTree(BiTree& T) {//���򴴽�������
	char root;
	scanf("%c", &root);
	if (root == ' ') {//���� ֹͣ
		T = NULL;
		return false;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) {
			printf("��ʼ������ʧ��");
			exit(1);
		}
		T->data = root;//��
		createBiTree(T->lchild);//��
		createBiTree(T->rchild);//��
	}
	return true;
}

void preOrder(BiTree T) {//���������ӡ������
	if (T == NULL) {
		return;
	}
	else {
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}


void inOrder(BiTree T) {//���������ӡ������
	if (T == NULL) {
		return;
	}
	else {
		inOrder(T->lchild);
		printf("%c ", T->data);
		inOrder(T->rchild);
	}
}

void postOrder(BiTree T) {//���������ӡ������
	if (T == NULL) {
		return;
	}
	else {
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);
	}
}
