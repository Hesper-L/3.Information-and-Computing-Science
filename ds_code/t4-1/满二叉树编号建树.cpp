#include <stdio.h>
#include "function.h"
#include "tree.h"

int main() {
		PTree P;
		printf("******������������ŷ�ʽ������������******\n");
		printf("\n��1-n��˳���������ڵ㣺\n");
		//����ABDC*
		createPTree(P);
		printf("\n��α��������Ϊ��\n");
		visitPT(P);
		printf("\n\n****************��end��****************\n");
		return 0;
}