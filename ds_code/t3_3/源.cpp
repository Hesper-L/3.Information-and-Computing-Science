#include <stdio.h>
#include <stdlib.h>//malloc函数和free函数

#define M 8
#define N 8
#define MaxStackSize 100//定义顺序栈最大空间

//
typedef struct {
	int i;//当前方块的行号
	int j;//当前方块的列号
	int di;//方块方向属性
}Box;//定义路径属性

typedef struct {
	Box data[MaxStackSize];//栈保存当前路径
	int top;
}SeqStack;//顺序栈

int mg[M + 2][N + 2] = //地图
{ {1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1} };

//初始化栈 
void StackInitiate(SeqStack*& S) {
	S = (SeqStack*)malloc(sizeof(SeqStack));
	if (S == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //解决对NULL指针的引用方法
	}
	S->top = -1;//初始化栈顶指针
}

//取出栈顶元素 
void StackTop(SeqStack*& S, Box& e) {
	e = S->data[S->top];
}

//压栈 
void StackPush(SeqStack*& S, Box& e) {
	S->top++;
	S->data[S->top] = e;
}

//出栈 
void StackPop(SeqStack*& S, Box& e) {
	e = S->data[S->top];
	S->top--;
}

//销毁栈
void DestroyStack(SeqStack*& S) {
	free(S);
}

//检验栈是否为空 
bool StackNotEmpty(SeqStack*& S) {
	if (S->top == -1)
		return false;
	return true;
}

bool mgpath(int xi, int yi, int xe, int ye)//求解路径为(xi,yi)->(xe,ye)
{
	SeqStack* S;				//定义栈S 
	StackInitiate(S);			//初始化栈
	Box path[MaxStackSize], e;	//path数组用来记录迷宫路径，e用来记录栈顶元素 
	mg[xi][yi] = -1;			//将起点压栈并将状态记录为-1（已走）
	int i, j, di;				//i,j,di用于记录栈顶元素状态
	e.i = xi, e.j = yi, e.di = -1;
	StackPush(S, e);

	int in, jn;					//用于记录下一方位的方块行列坐标 
	int find;					//记录是否找到相邻可走元素 
	find = 0;					//初始化为0，未找到可走相邻方块 

	while (StackNotEmpty(S))	//栈不空时循环
	{
		StackTop(S, e);			//取出栈顶元素 
		i = e.i, j = e.j, di = e.di;
		if (i == xe && j == ye)	//找到出口，输出该路径
		{
			printf("一条迷宫路径如下:\n");
			int k = 0;
			while (StackNotEmpty(S)) {
				StackPop(S, e);
				path[k++] = e;
			}
			while (k >= 1) {
				k--;
				printf("\t(%d,%d)", path[k].i, path[k].j);
				if ((k + 2) % 5 == 0)
					printf("\n");	//每输出5个方块后换一行 
			}
			printf("\n");
			DestroyStack(S);
			return true;		//输出一条路径后返回true并销毁数据栈
		}
		while (di < 4 && find == 0)	//不是出口则继续查找
		{
			di++;
			switch (di) {
			case 0: {in = i - 1, jn = j; break; }//左
			case 1: {in = i; jn = j + 1; break; }//下
			case 2: {in = i + 1; jn = j; break; }//右
			case 3: {in = i; jn = j - 1; break; }//上
			}
			if (mg[in][jn] == 0)	//找到可走相邻方块 
				find = 1;
		}
		if (find) {
			S->data[S->top].di = di; //修改原栈顶元素的di值 
			e.i = in, e.j = jn, e.di = -1;
			StackPush(S, e);		//相邻可走方块e进栈
			mg[in][jn] = -1;		//将状态记录为-1（已走），防止重复
		}
		else {	//没有可走相邻方块 
			StackPop(S, e);			//没有路径可走，将当前方块退栈 
			mg[e.i][e.j] = 0;		//将退栈方块位置的值恢复为0 
		}
	}
	DestroyStack(S);
	return false;		//表示没有可走路径，销毁栈 
}

int main() {
	if (!mgpath(1, 1, M, N))
		printf("该迷宫问题没有解");
	return 0;
}
