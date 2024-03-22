#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "tree.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

bool createBiTree(BiTree& T) {//先序创建二叉树
	char root;
	scanf("%c", &root);
	if (root == ' ') {//遇到 停止
		T = NULL;
		return false;
	}
	else {
		T = (BiTree)malloc(sizeof(BiTNode));
		if (!T) {
			printf("初始化变量失败");
			exit(1);
		}
		T->data = root;//根
		createBiTree(T->lchild);//左
		createBiTree(T->rchild);//右
	}
	return true;
}

void preOrder(BiTree T) {//先序遍历打印二叉树
	if (T == NULL) {
		return;
	}
	else {
		printf("%c ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}


void inOrder(BiTree T) {//中序遍历打印二叉树
	if (T == NULL) {
		return;
	}
	else {
		inOrder(T->lchild);
		printf("%c ", T->data);
		inOrder(T->rchild);
	}
}

void postOrder(BiTree T) {//后序遍历打印二叉树
	if (T == NULL) {
		return;
	}
	else {
		postOrder(T->lchild);
		postOrder(T->rchild);
		printf("%c ", T->data);
	}
}
