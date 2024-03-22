#pragma once

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;//左右孩子指针 
}BiTNode, * BiTree;

// 先序输入创建二叉树
bool createBiTree(BiTree& T);
//先序遍历读取
void preOrder(BiTree T);
//中序遍历读取
void inOrder(BiTree T);
//后序遍历读取
void postOrder(BiTree T);