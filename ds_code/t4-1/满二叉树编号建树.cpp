#include <stdio.h>
#include "function.h"
#include "tree.h"

int main() {
		PTree P;
		printf("******【满二叉树编号方式建立二叉树】******\n");
		printf("\n按1-n的顺序输入树节点：\n");
		//输入ABDC*
		createPTree(P);
		printf("\n层次遍历输出树为：\n");
		visitPT(P);
		printf("\n\n****************【end】****************\n");
		return 0;
}