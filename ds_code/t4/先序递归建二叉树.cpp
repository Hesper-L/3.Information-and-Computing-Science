#include <stdio.h>
#include "tree.h"
#include "function.h"


int main() {
	BiTree T;
	printf("********������ݹ齨����������********\n\n");
	printf("Enter a series of characters ending with a space(����ǰ���������\n");
	//����ABC##D##E##���ÿո����#��
	createBiTree(*&T);
	printf("\nThe preorder traversal is shown below(ǰ��������):\n");
	preOrder(T);
	printf("\n\nThe inorder traversal is shown below(����������):\n");
	inOrder(T);
	printf("\n\nThe postorder traversal is shown below(����������):\n");
	postOrder(T);
	printf("\n\n****************��end��****************\n");
	return 0;
}