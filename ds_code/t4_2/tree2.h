#define _CRT_SECURE_NO_DEPRECATE 
#include "tree2.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

// 先序输入创建二叉树
Status CreateBiTree(BiTree& T) {
	char ch;
	scanf("%c", &ch);
	// 空格表示空（子）树
	if (ch == ' ') T = NULL;
	else {
		// 创建节点
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) return ERROR;
		T->data = ch;
		// 先序
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

//先序遍历读取
void PreOrderTraverse(BiTree T) {
	if (T == NULL) return;
	cout << T->data << ' ';
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//中序遍历读取
void InOrderTraverse(BiTree T) {
	if (T == NULL) return;
	InOrderTraverse(T->lchild);
	cout << T->data << ' ';
	InOrderTraverse(T->rchild);
}

//后序遍历读取
void PostOrderTraverse(BiTree T) {
	if (T == NULL) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << ' ';
}