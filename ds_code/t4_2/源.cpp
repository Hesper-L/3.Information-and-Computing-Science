#include <stdio.h>
#include "tree2.h"
#include "tree.h"

int main() {
	BiTree T;
	printf("前序遍历输入\n");
	CreateBiTree(T);
	printf("\n前序遍历输出\n");
	PreOrderTraverse(T);
	printf("\n中序遍历输出\n");
	InOrderTraverse(T);
	printf("\n后序遍历输出\n");
	PostOrderTraverse(T);

	return 0;
}