
//---------����ƥ������---------

//˵�������Բ���š������š������ŵĲ��Ƕ���Ƿ���ȷ��
//�磬��̹��ߵķ�����ʾ��
//���ڽ�����������ؽ����������(1+2)*5+6=?����׺�������ʽ
//�����ݴ˽��˼·��˳��������ѹ���ջ�У�����ƥ��������ٵ����������㣬��ѹ���ջ
//

//����ƥ������У�
/*
1. �����Ŷ���������
2. �����Ŷ���������
3. ����������Դ�����ȷ
4. ��������ƥ����ȷ
*/


#include<stdio.h>
#include<string.h>

#define MaxStackSize 100
typedef char DataType;

typedef struct {
	DataType stack[MaxStackSize];
	int top;
}SeqStack;

//��ʼ��˳���ջS
void StackInitiate(SeqStack* S) {
	S->top = 0;
}

//�ǿշ��ж�˳���ջS�Ƿ�գ��ǿ��򷵻�1�����򷵻�0
int StackNotEmpty(SeqStack S) {
	if (S.top <= 0)
		return 0;
	else
		return 1;
}

//ѹջ��������Ԫ�ص�ֵx����˳���ջS�У�ѹջ�ɹ�����1�����򷵻�0
int StackPush(SeqStack* S, DataType x) {
	if (S->top >= MaxStackSize) {
		printf("��ջ�����޷����룡\n");
		return 0;
	}
	else {
		S->stack[S->top] = x;
		S->top++;
		return 1;
	}
}

//��ջ:ȡ��˳���ջS��ջ������Ԫ��ֵ�ɲ���d���أ���ջ�ɹ�����1�����򷵻�0
int StackPop(SeqStack* S, DataType* d) {
	if (S->top <= 0) {
		printf("��ջ�ѿգ�������Ԫ�ؿɳ�ջ��\n");
		return 0;
	}
	else {
		S->top--;
		*d = S->stack[S->top];
		return 1;
	}
}

//ȡջ������Ԫ��:ȡ˳��ջ��S�ĵ�ǰջ������Ԫ��ֵ�ɲ���d���أ��ɹ�����1�����򷵻�0
int StackTop(SeqStack S, DataType* d) {
	if (S.top <= 0) {
		printf("ջ���ѿգ�");
		return 0;
	}
	else {
		*d = S.stack[S.top - 1];
		return 1;
	}
}


//�ж���n���ַ����ַ���expƥ���Ƿ���ȷ
void IsBracketCorrect(char exp[], int n) {
	SeqStack myStack;//����˳���ջ������mystack��
	char c;
	StackInitiate(&myStack);//��ʼ��˳���ջ
	for (int i = 0; i < n; i++) {
		if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')) {
			StackPush(&myStack, exp[i]);//ѹջ
		}
		else if (exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '(') {
			StackPop(&myStack, &c);//��ջ
		}
		else if (exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '(') {
			printf("��������ƥ�������ȷ��\n");
			return;
		}
		else if (exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '[') {
			StackPop(&myStack, &c);//��ջ
		}
		else if (exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '[') {
			printf("��������ƥ�������ȷ��\n");
			return;
		}
		else if (exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '{') {
			StackPop(&myStack, &c);//��ջ
		}
		else if (exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '{') {
			printf("��������ƥ�������ȷ��\n");
			return;
		}
		else if (((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) && !StackNotEmpty(myStack)) {
			printf("�����Ŷ��������ţ�\n");
			return;
		}
	}

	if (StackNotEmpty(myStack)) {
		printf("�����Ŷ��������ţ�\n");
	}
	else {
		printf("��������ƥ����ȷ��\n");
	}
}


//������������
int main() {
	//����
	char a[] = "(())abc{[)(]}";//����1����������ƥ�������ȷ
	char b[] = "(()))abc{[]}";//����2�������Ŷ���������
	char c[] = "(()()abc{[]}";//����3�������Ŷ���������
	char d[] = "(())abc{[]}";//����4����������ƥ����ȷ

	//�����ַ����ĳ���
	int n1 = int(strlen(a));
	int n2 = int(strlen(b));
	int n3 = int(strlen(c));
	int n4 = int(strlen(d));

	//����
	IsBracketCorrect(a, n1);
	IsBracketCorrect(b, n2);
	IsBracketCorrect(c, n3);
	IsBracketCorrect(d, n4);

	return 0;
}