#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<malloc.h>
#define MaxSize 10


//�������� ����visit
inline void visit(BiTree p) {
	printf("%d ", p->data);
}


//����������������ʽ(������Ƚ���)
bool CreateBiTree_BiTNode(BiTree& T) {
	DataType root;
	scanf("%d", &root);
	//�������������   
	if (root == 0) { //�ж��Ƿ�Ϊ��        
		T = NULL;
		return false;
	}
	else {
		T = (BiTNode*)malloc(sizeof(BiTNode));  //������������       
		if (!T) {
			printf("��ʼ������ʧ��");
			exit(1);
		}
		T->data = root;
		printf(" �������½��ڵ㲢�Ѳ�������%d", T->data);
		printf("\n");
		CreateBiTree_BiTNode(T->lchild);
		CreateBiTree_BiTNode(T->rchild);
	}
	return true;
}


//==============================================��������


//��ʼ��
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

//���
bool EnQueue(SqQueue& q, ElemType x) {
	if ((q.rear + 1) % MaxSize == q.front) {        //��������
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;        //�ƶ�����β
	return true;
}

//����
bool DeQueue(SqQueue& q, ElemType& x) {
	if (q.front == q.rear) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

//�������
void LevelTraverse(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p; //����ָ�� �������Ԫ�ظ������

	EnQueue(Q, T);      //���ڵ����
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);      //���ӽ���p       
		visit(p);    //����
		if (p->lchild) {      //���Ӳ������
			EnQueue(Q, p->lchild);
		}
		if (p->rchild) {
			EnQueue(Q, p->rchild);
		}
	}
}

/*����һ��������Һ��ӻ��Һ���Ϊ�գ�
�������н��ĺ��ӱ�ȻȫΪ�գ���������ȫ��������
��������ȫ��������"

��ô�����ǿ��Բ��ö������Ĳ������������
�����н�㣨�����սڵ㣩ȫ����ӣ�
������һ������Ϊ�յĽڵ�����������Ƿ��зǿյĽڵ㣬
�еĻ�������ȫ��������û��������ȫ��������*/
bool IsComplete1(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	p = T;
	if (!p) {
		return true;        //��������ȫ������
	}
	EnQueue(Q, p);      //���
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);
		if (p) {  //ȫ����� ������һ���սڵ�ת��else
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else {      //�����սڵ�ʱ��ʼ���������Ƿ�������ȫ������
			while (!QueueEmpty(Q)) {
				DeQueue(Q, p);
				if (p) {
					return false;
				}
			}
		}
	}
	return true;        //����ȫ������
}

/*��Ȼ���ò���������������ǲ��ѿսڵ���ӣ��������ö���ı�ʶ����
����Ƿ���������Ϊ�յĽ�㣬���ӽ������ı����������������Ϊ�յĽ��ʱ��
�������Ƿ���ں��Ӳ�Ϊ�յĽ�㣬�������ǣ����������ǡ���
�ж������Ƿ�����ȫ���������÷���Ҫ�Խ������Һ��ӷֱ�����ж���

  �������ң�����
  ��ǰ�ڵ����ң����Ӳ��գ���֮ǰû����������Ϊ�յĽڵ㣬��ӵ�ǰ�ڵ����ң����ӣ�
  ��ǰ�ڵ����ң����Ӳ��գ���֮ǰ����������Ϊ�յĽڵ㣬��������ȫ��������
  �״���������Ϊ�յĽڵ㣬����ʶ����Ϊtrue��*/
bool IsComplete2(BiTree T) {
	//���������ѿսڵ���ӣ����ñ�ʶ��
	SqQueue Q;
	BiTree p;
	InitQueue(Q);
	p = T;
	bool existEmpty = false;
	//���ĳ���ڵ����޺��� ����û�к��ӵĽڵ���Ϊtrue ����Ϊfalse
	if (!p) {
		return true;
	}
	EnQueue(Q, p);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, p);

		//����������
		if (p->lchild && existEmpty == false) {
			//��ǰ�ڵ����Ӳ��� ��֮ǰû����������Ϊ�յĽڵ� ��ӵ�ǰ�ڵ�����
			EnQueue(Q, p->lchild);
		}
		else if (p->lchild && existEmpty == true) {
			//��ǰ�ڵ����Ӳ��� ��֮ǰ����������Ϊ�յĽڵ� ��������ȫ������
			return false;
		}
		else if (p->lchild == NULL && existEmpty == true) {
			//�״���������Ϊ�յĽڵ�
			existEmpty = true;
		}

		//������������ͬ�� һ����֤��ǰ�ڵ��Һ���
		if (p->rchild && existEmpty == false) {
			//��ǰ�ڵ��Һ��Ӳ��� ��֮ǰû����������Ϊ�յĽڵ� ��ӵ�ǰ�ڵ��Һ���
			EnQueue(Q, p->rchild);
		}
		else if (p->rchild && existEmpty == true) {
			//��ǰ�ڵ��Һ��Ӳ��� ��֮ǰ����������Ϊ�յĽڵ� ��������ȫ������
			return false;
		}
		else if (p->rchild == NULL && existEmpty == true) {
			//�״���������Ϊ�յĽڵ�
			existEmpty = true;
		}
	}
	return true;
}

//�ж���������
int main() {
	BiTree T1;
	printf("Enter a series of characters ending with a space:\n(��ʾ�����밢��������)\n");
	//��������1��yes��
	//1 2 3 0 0 4 0 0 5 0 0
	//��������2��no��
	//1 2 0 3 0 0 4 5 0 0 0
	CreateBiTree_BiTNode(*&T1);
	printf("\n������T1Ϊ��\n");
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

