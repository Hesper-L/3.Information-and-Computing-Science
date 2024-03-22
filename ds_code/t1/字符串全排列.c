#define _CRT_SECURE_NO_WARNINGS				//#pragma warning(distable:4996) 
#include<stdio.h>							
#include<string.h>

char str[10], temp[10];						//temp用来输出全排列的每一个结果
int len;
int flag[10];								//用来判断str中的第i个位置字符是否进行了此次排列 
void dfs(int step) {						//当step=0,执行的dfs(0),选定了temp第一位字母，执行dfs(1),选定temp第二位字母，以此类推
	if (step == len) {						//只要执行的是dfs(step),temp的第step+1位的字母就被选定 
		temp[step] = '\0';
		printf("%s\n", temp);
	}
	for (int i = 0; i < len; i++) {
		if (flag[i] == 0) {
			flag[i] = 1;
			temp[step] = str[i];			//temp[step]的值由i和 flag[i]共同决定
			dfs(step + 1);
			flag[i] = 0;					//每一次dfs(step+1)调用完成后flag[i]被置为0，str[i]又回到了未被排序的状态 
		}
	}
}
int main() {
	printf("请输入您想要全排列的组合：\n");
	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		printf("全排列结果如下：\n");
		dfs(0);
	}
	return 0;
}
