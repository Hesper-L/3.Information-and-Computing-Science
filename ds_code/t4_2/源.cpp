#include <stdio.h>
#include "tree2.h"
#include "tree.h"

int main() {
	BiTree T;
	printf("ǰ���������\n");
	CreateBiTree(T);
	printf("\nǰ��������\n");
	PreOrderTraverse(T);
	printf("\n����������\n");
	InOrderTraverse(T);
	printf("\n����������\n");
	PostOrderTraverse(T);

	return 0;
}