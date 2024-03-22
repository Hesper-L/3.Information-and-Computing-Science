#include <stdio.h>
#include <stdlib.h>//malloc������free����

#define M 8
#define N 8
#define MaxStackSize 100//����˳��ջ���ռ�

//
typedef struct {
	int i;//��ǰ������к�
	int j;//��ǰ������к�
	int di;//���鷽������
}Box;//����·������

typedef struct {
	Box data[MaxStackSize];//ջ���浱ǰ·��
	int top;
}SeqStack;//˳��ջ

int mg[M + 2][N + 2] = //��ͼ
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

//��ʼ��ջ 
void StackInitiate(SeqStack*& S) {
	S = (SeqStack*)malloc(sizeof(SeqStack));
	if (S == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //�����NULLָ������÷���
	}
	S->top = -1;//��ʼ��ջ��ָ��
}

//ȡ��ջ��Ԫ�� 
void StackTop(SeqStack*& S, Box& e) {
	e = S->data[S->top];
}

//ѹջ 
void StackPush(SeqStack*& S, Box& e) {
	S->top++;
	S->data[S->top] = e;
}

//��ջ 
void StackPop(SeqStack*& S, Box& e) {
	e = S->data[S->top];
	S->top--;
}

//����ջ
void DestroyStack(SeqStack*& S) {
	free(S);
}

//����ջ�Ƿ�Ϊ�� 
bool StackNotEmpty(SeqStack*& S) {
	if (S->top == -1)
		return false;
	return true;
}

bool mgpath(int xi, int yi, int xe, int ye)//���·��Ϊ(xi,yi)->(xe,ye)
{
	SeqStack* S;				//����ջS 
	StackInitiate(S);			//��ʼ��ջ
	Box path[MaxStackSize], e;	//path����������¼�Թ�·����e������¼ջ��Ԫ�� 
	mg[xi][yi] = -1;			//�����ѹջ����״̬��¼Ϊ-1�����ߣ�
	int i, j, di;				//i,j,di���ڼ�¼ջ��Ԫ��״̬
	e.i = xi, e.j = yi, e.di = -1;
	StackPush(S, e);

	int in, jn;					//���ڼ�¼��һ��λ�ķ����������� 
	int find;					//��¼�Ƿ��ҵ����ڿ���Ԫ�� 
	find = 0;					//��ʼ��Ϊ0��δ�ҵ��������ڷ��� 

	while (StackNotEmpty(S))	//ջ����ʱѭ��
	{
		StackTop(S, e);			//ȡ��ջ��Ԫ�� 
		i = e.i, j = e.j, di = e.di;
		if (i == xe && j == ye)	//�ҵ����ڣ������·��
		{
			printf("һ���Թ�·������:\n");
			int k = 0;
			while (StackNotEmpty(S)) {
				StackPop(S, e);
				path[k++] = e;
			}
			while (k >= 1) {
				k--;
				printf("\t(%d,%d)", path[k].i, path[k].j);
				if ((k + 2) % 5 == 0)
					printf("\n");	//ÿ���5�������һ�� 
			}
			printf("\n");
			DestroyStack(S);
			return true;		//���һ��·���󷵻�true����������ջ
		}
		while (di < 4 && find == 0)	//���ǳ������������
		{
			di++;
			switch (di) {
			case 0: {in = i - 1, jn = j; break; }//��
			case 1: {in = i; jn = j + 1; break; }//��
			case 2: {in = i + 1; jn = j; break; }//��
			case 3: {in = i; jn = j - 1; break; }//��
			}
			if (mg[in][jn] == 0)	//�ҵ��������ڷ��� 
				find = 1;
		}
		if (find) {
			S->data[S->top].di = di; //�޸�ԭջ��Ԫ�ص�diֵ 
			e.i = in, e.j = jn, e.di = -1;
			StackPush(S, e);		//���ڿ��߷���e��ջ
			mg[in][jn] = -1;		//��״̬��¼Ϊ-1�����ߣ�����ֹ�ظ�
		}
		else {	//û�п������ڷ��� 
			StackPop(S, e);			//û��·�����ߣ�����ǰ������ջ 
			mg[e.i][e.j] = 0;		//����ջ����λ�õ�ֵ�ָ�Ϊ0 
		}
	}
	DestroyStack(S);
	return false;		//��ʾû�п���·��������ջ 
}

int main() {
	if (!mgpath(1, 1, M, N))
		printf("���Թ�����û�н�");
	return 0;
}
