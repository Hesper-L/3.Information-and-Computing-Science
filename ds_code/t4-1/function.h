#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include "tree.h"
#include <malloc.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;


// 输入创建满二叉树
bool createPTree(PTree& T) {
	char c = 'A';
	if (T.n < 0) T.n = 0;
	// * 表示空
	while (c != '*') {
		PTNode P;
		scanf("%c", &c);
		P.data = c;
		T.nodes[T.n++] = P;
	}
	int depth = 0;
	int all = T.n;
	int temp = 1;
	while (all > 0) {
		all -= temp;
		depth++;
		temp *= 2;
	}
	while (T.n < pow(2, depth) - 1) {
		PTNode P;
		P.data = '*';
		T.nodes[T.n++] = P;
	}
	return true;
}

void visitPT(PTree& T) {
	int len = T.n;
	while (len-- > 0) {
		cout << T.nodes[T.n - len - 1].data << ' ';
	}
}
