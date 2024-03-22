#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<malloc.h>
#define MaxSize 10


//操作函数 负责visit
inline void visit(BiTree p) {
	printf("%d ", p->data);
}


//二叉树建立二叉链式(深度优先建树)
bool CreateBiTree_BiTNode(BiTree& T) {
	DataType root;
	scanf("%d", &root);
	//输入二叉树数据   
	if (root == 0) { //判断是否为空        
		T = NULL;
		return false;
	}
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));  //二叉树的生成       
		if (!T) {
			printf("初始化变量失败");
			exit(1);
		}
		T->data = root;
		printf(" 二叉树新建节点并已插入数据%d", T->data);
		printf("\n");
		CreateBiTree_BiTNode(T->lchild);
		CreateBiTree_BiTNode(T->rchild);
	}
	return true;
}


//==============================================辅助队列


//初始化
void InitQueue(SqQueue& q) {
	q.front = q.rear = 0;
}

bool QueueEmpty(SqQueue q) {
	if (q.front == q.rear) {
		return true;
	}
	else {
		return false;
	}
}

//入队
bool EnQueue(SqQueue& q, ElemType x) {
	if ((q.rear + 1) % MaxSize == q.front) {        //队列已满
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;        //移动队列尾
	return true;
}

//出队
bool DeQueue(SqQueue& q, ElemType& x) {
	if (q.front == q.rear) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

//层序遍历
void LevelTraverse(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p; //工作指针 保存出队元素负责访问

	EnQueue(Q, T);      //根节点入队
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);      //出队交给p       
		visit(p);    //访问
		if (p->lchild) {      //左孩子不空入队
			EnQueue(Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(Q, p->rchild);
		}
	}
}

/*“若一个结点左右孩子或右孩子为空，
后面所有结点的孩子必然全为空，则满足完全二叉树，
否则不是完全二叉树。"

那么，我们可以采用二叉树的层序遍历方法，
将所有结点（包括空节点）全部入队，
遇到第一个孩子为空的节点则检查其后面是否还有非空的节点，
有的话不是完全二叉树，没有则是完全二叉树。*/
bool IsComplete1(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	p = T;
	if (!p) {
		return true;        //空树是完全二叉树
	}
	EnQueue(Q, p);      //入队
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);
		if (p) {  //全部入队 遇到第一个空节点转到else
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else {      //遇到空节点时开始检查队列中是否满足完全二叉树
			while (!QueueEmpty(Q)) {
				DeQueue(Q, p);
				if (p) {
					return false;
				}
			}
		}
	}
	return true;        //是完全二叉树
}

/*仍然采用层序遍历方法，但是不把空节点入队，改用设置额外的标识器，
标记是否遇到孩子为空的结点，再视接下来的遍历结果（遇到孩子为空的结点时，
接下来是否存在孩子不为空的结点，存在则不是，不存在则是。）
判定该树是否是完全二叉树，该方法要对结点的左右孩子分别进行判定。

  处理左（右）子树
  当前节点左（右）孩子不空，且之前没有遇到孩子为空的节点，入队当前节点左（右）孩子；
  当前节点左（右）孩子不空，且之前遇到过孩子为空的节点，并不是完全二叉树；
  首次遇到孩子为空的节点，将标识器置为true；*/
bool IsComplete2(BiTree T) {
	//本方法不把空节点入队，设置标识器
	SqQueue Q;
	BiTree p;
	InitQueue(Q);
	p = T;
	bool existEmpty = false;
	//标记某个节点有无孩子 遇到没有孩子的节点置为true 否则为false
	if (!p) {
		return true;
	}
	EnQueue(Q, p);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);

		//处理左子树
		if (p->lchild && existEmpty == false) {
			//当前节点左孩子不空 且之前没有遇到孩子为空的节点 入队当前节点左孩子
			EnQueue(Q, p->lchild);
		}
		else if (p->lchild && existEmpty == true) {
			//当前节点左孩子不空 且之前遇到过孩子为空的节点 并不是完全二叉树
			return false;
		}
		else if (p->lchild == NULL && existEmpty == true) {
			//首次遇到孩子为空的节点
			existEmpty = true;
		}

		//与左子树处理同理 一样验证当前节点右孩子
		if (p->rchild && existEmpty == false) {
			//当前节点右孩子不空 且之前没有遇到孩子为空的节点 入队当前节点右孩子
			EnQueue(Q, p->rchild);
		}
		else if (p->rchild && existEmpty == true) {
			//当前节点右孩子不空 且之前遇到过孩子为空的节点 并不是完全二叉树
			return false;
		}
		else if (p->rchild == NULL && existEmpty == true) {
			//首次遇到孩子为空的节点
			existEmpty = true;
		}
	}
	return true;
}

//判定函数部分
int main() {
	BiTree T1;
	printf("Enter a series of characters ending with a space:\n(提示：输入阿拉伯数字)\n");
	//测试用例1（yes）
	//1 2 3 0 0 4 0 0 5 0 0
	//测试用例2（no）
	//1 2 0 3 0 0 4 5 0 0 0
	CreateBiTree_BiTNode(*&T1);
	printf("\n二叉树T1为：\n");
	LevelTraverse(T1);
	printf("\n");
	bool IS = IsComplete1(T1);
	//bool IS = IsComplete2(T1);
	if (IS == true) {
		printf("yes!");
	}
	else {
		printf("no!");
	}

	return 0;
}

