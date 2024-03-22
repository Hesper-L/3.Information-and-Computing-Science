
//---------括号匹配问题---------

//说明：解决圆括号、方括号、花括号的层层嵌套是否正确。
//如，编程工具的符合提示。
//对于解决带运算的相关解决方案，如(1+2)*5+6=?等中缀算术表达式
//可依据此解决思路，顺带把数字压入堆栈中，遇到匹配的括号再弹出进行运算，再压入堆栈
//

//括号匹配情况有：
/*
1. 左括号多于右括号
2. 右括号多于左括号
3. 左右括号配对次序不正确
4. 左、右括号匹配正确
*/


#include<stdio.h>
#include<string.h>

#define MaxStackSize 100
typedef char DataType;

typedef struct {
	DataType stack[MaxStackSize];
	int top;
}SeqStack;

//初始化顺序堆栈S
void StackInitiate(SeqStack* S) {
	S->top = 0;
}

//非空否：判断顺序堆栈S是否空，非空则返回1，否则返回0
int StackNotEmpty(SeqStack S) {
	if (S.top <= 0)
		return 0;
	else
		return 1;
}

//压栈：把数据元素的值x存入顺序堆栈S中，压栈成功返回1，否则返回0
int StackPush(SeqStack* S, DataType x) {
	if (S->top >= MaxStackSize) {
		printf("堆栈已满无法插入！\n");
		return 0;
	}
	else {
		S->stack[S->top] = x;
		S->top++;
		return 1;
	}
}

//出栈:取出顺序堆栈S的栈顶数据元素值由参数d带回，出栈成功返回1，否则返回0
int StackPop(SeqStack* S, DataType* d) {
	if (S->top <= 0) {
		printf("堆栈已空，无数据元素可出栈！\n");
		return 0;
	}
	else {
		S->top--;
		*d = S->stack[S->top];
		return 1;
	}
}

//取栈顶数据元素:取顺序栈顶S的当前栈顶数据元素值由参数d带回，成功返回1，否则返回0
int StackTop(SeqStack S, DataType* d) {
	if (S.top <= 0) {
		printf("栈顶已空！");
		return 0;
	}
	else {
		*d = S.stack[S.top - 1];
		return 1;
	}
}


//判断有n个字符的字符串exp匹配是否正确
void IsBracketCorrect(char exp[], int n) {
	SeqStack myStack;//定义顺序堆栈变量“mystack”
	char c;
	StackInitiate(&myStack);//初始化顺序堆栈
	for (int i = 0; i < n; i++) {
		if ((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{')) {
			StackPush(&myStack, exp[i]);//压栈
		}
		else if (exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '(') {
			StackPop(&myStack, &c);//出栈
		}
		else if (exp[i] == ')' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '(') {
			printf("左右括号匹配次序不正确！\n");
			return;
		}
		else if (exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '[') {
			StackPop(&myStack, &c);//出栈
		}
		else if (exp[i] == ']' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '[') {
			printf("左右括号匹配次序不正确！\n");
			return;
		}
		else if (exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c == '{') {
			StackPop(&myStack, &c);//出栈
		}
		else if (exp[i] == '}' && StackNotEmpty(myStack) && StackTop(myStack, &c) && c != '{') {
			printf("左右括号匹配次序不正确！\n");
			return;
		}
		else if (((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}')) && !StackNotEmpty(myStack)) {
			printf("右括号多于左括号！\n");
			return;
		}
	}

	if (StackNotEmpty(myStack)) {
		printf("左括号多于右括号！\n");
	}
	else {
		printf("左右括号匹配正确！\n");
	}
}


//测试主函数：
int main() {
	//例子
	char a[] = "(())abc{[)(]}";//案例1，左右括号匹配次序不正确
	char b[] = "(()))abc{[]}";//案例2，右括号多于左括号
	char c[] = "(()()abc{[]}";//案例3，左括号多于又括号
	char d[] = "(())abc{[]}";//案例4，左右括号匹配正确

	//各个字符串的长度
	int n1 = int(strlen(a));
	int n2 = int(strlen(b));
	int n3 = int(strlen(c));
	int n4 = int(strlen(d));

	//测试
	IsBracketCorrect(a, n1);
	IsBracketCorrect(b, n2);
	IsBracketCorrect(c, n3);
	IsBracketCorrect(d, n4);

	return 0;
}