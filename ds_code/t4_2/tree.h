#pragma once
#pragma once

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//左右孩子指针 
}BiTNode, * BiTree;

typedef bool Status;
#define OK true;
#define ERROR false;

// 先序输入创建二叉树
Status CreateBiTree(BiTree& T);
//先序遍历读取
void PreOrderTraverse(BiTree T);
//中序遍历读取
void InOrderTraverse(BiTree T);
//后序遍历读取
void PostOrderTraverse(BiTree T);