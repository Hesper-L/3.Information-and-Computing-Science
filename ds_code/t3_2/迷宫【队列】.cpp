#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4

typedef struct
{
	int i, j; //��¼���������������
	int pre;  //��¼��·����һ�����ڶ����е��±�
} Box;

typedef struct
{
	Box data[1000];
	int front, rear; //��ͷ��βָ��
} Que;

int mg[M + 2][N + 2] =
{ {1, 1, 1, 1, 1, 1},
 {1, 0, 0, 0, 1, 1},
 {1, 0, 1, 0, 0, 1},
 {1, 0, 0, 0, 1, 1},
 {1, 1, 0, 0, 0, 1},
 {1, 1, 1, 1, 1, 1} };

void InitQue(Que*& qu)
{
	qu = (Que*)malloc(sizeof(Que));
	if (qu == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //�����NULLָ������÷���
	}
	qu->front = qu->rear = -1;
}

int EmptyQue(Que*& qu)
{
	return (qu->front == qu->rear);
}

int Push(Que*& qu, Box& e)
{
	if (qu->rear > 999)
		return 0;
	e.pre = qu->front;
	qu->rear++;
	qu->data[qu->rear] = e;		//C6386�����������
	return 1;
}

int Pop(Que*& qu, Box& e)
{
	if (EmptyQue(qu))
		return 0;
	qu->front++;
	e = qu->data[qu->front];
	return 1;
}

void print(Que*& qu, int k)
{
	int j;
	//����Ѱ�����·��
	while (k != -1)
	{
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1; //���ҵ���·���ϵķ����pre��Ա��Ϊ-1
	}

	k = 0;
	int ns = 0;
	while (k < 1000)
	{ //���������������pre��ԱΪ-1�ķ�������
		if (qu->data[k].pre == -1)
		{
			ns++;
			printf("\t(%d,%d)", qu->data[k].i, qu->data[k].j);
			if (ns % 5 == 0)
				printf("\n"); //ÿ���5��Ԫ�غ�һ��
		}
		k++;
	}
	printf("\n");
}

void DestroyQue(Que*& qu)
{
	free(qu);
}

int mgpath1(int xi, int yi, int xe, int ye)
{
	Box e;
	int i, j, pre;
	Que* qu;
	InitQue(qu); //��ʼ������

	//������
	e.i = xi, e.j = yi, e.pre = -1;
	mg[xi][yi] = -1;
	Push(qu, e);

	while (!EmptyQue(qu))
	{								   //���в�����ѭ��
		Pop(qu, e);					   //����Ԫ�س���
		i = e.i, j = e.j, pre = e.pre; //��¼��ǰ����Ԫ�صķ�����
		if (i == xe && j == ye) {		//����Ԫ��Ϊ���������·��
			printf("�Թ�·������:\n");
			print(qu, qu->front); //���·������
			return 1;
		}

		int d = -1;
		int in, jn;
		while (d < 4)
		{ //ÿ����λ������̽
			d++;
			switch (d)
			{
			case 0:
			{
				in = i - 1, jn = j;
				break;
			}
			case 1:
			{
				in = i;
				jn = j + 1;
				break;
			}
			case 2:
			{
				in = i + 1;
				jn = j;
				break;
			}
			case 3:
			{
				in = i;
				jn = j - 1;
				break;
			}
			}
			if (mg[in][jn] == 0)
			{ //�ҵ��������ڷ���(in,jn)�����
				e.i = in, e.j = jn, e.pre = qu->front;
				Push(qu, e);
				mg[in][jn] = -1; //���丳ֵ-1���Ա��������ظ�����
			}
		}
	}
	DestroyQue(qu); //���ٶ���
	return 0;
}

int main()
{
	if (!mgpath1(1, 1, M, N))
		printf("���Թ������޽�");

	return 0;
}
