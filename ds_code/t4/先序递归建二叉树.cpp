#include <stdio.h>
#include "tree.h"
#include "function.h"


int main() {
	BiTree T;
	printf("********【先序递归建立二叉树】********\n\n");
	printf("Enter a series of characters ending with a space(输入前序遍历）：\n");
	//输入ABC##D##E##（用空格代替#）
	createBiTree(*&T);
	printf("\nThe preorder traversal is shown below(前序遍历输出):\n");
	preOrder(T);
	printf("\n\nThe inorder traversal is shown below(中序遍历输出):\n");
	inOrder(T);
	printf("\n\nThe postorder traversal is shown below(后序遍历输出):\n");
	postOrder(T);
	printf("\n\n****************【end】****************\n");
	return 0;
}