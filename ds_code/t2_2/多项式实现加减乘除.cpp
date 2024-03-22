#include<iostream>
using namespace std;
//多项式的一项为链表的一个结点，有头结点
struct polynode
{
	int coef;
	int exp;
	polynode* link;
};
typedef polynode* polypointer;

//将多项式的一项加入链表的尾部
void Attach(int c, int e, polypointer& d)
{
	polypointer x;
	x = new polynode;
	x->coef = c;
	x->exp = e;
	d->link = x;
	x->link = NULL;
	d = d->link;
}
//用户输入多项式的一项
void Input(polypointer& L)
{
	int c, e;
	cout << "请输入一元多项式f/g：--格式是（系数 指数）以0 0结束" << endl;
	cin >> c >> e;
	polypointer p = L;
	while (c)
	{
		Attach(c, e, p);
		cout << "请输入一元多项式f的下一项：（以0 0结束）" << endl;
		cin >> c >> e;
	}
}

//加法函数，返回结点c指向L1
polypointer PolyAdd(polypointer L1, polypointer L2)
{
	polypointer p, q, d, c;
	int x;
	p = L1->link;
	q = L2->link;
	c = new polynode;
	c->link = NULL;
	d = c;
	while ((p != NULL) && (q != NULL))
	{
		if (p->exp == q->exp)
		{
			x = p->coef + q->coef;
			if (x != 0)
				Attach(x, p->exp, d);
			p = p->link;
			q = q->link;
		}
		else if (p->exp > q->exp)
		{
			Attach(p->coef, p->exp, d);
			p = p->link;
		}
		else if (p->exp < q->exp)
		{
			Attach(q->coef, q->exp, d);
			q = q->link;
		}
	}
	while (p != NULL)
	{
		Attach(p->coef, p->exp, d);
		p = p->link;
	}
	while (q != NULL)
	{
		Attach(q->coef, q->exp, d);
		q = q->link;
	}
	return c;
}

//减法函数,与加法函数相同
polypointer PolyMinus(polypointer L1, polypointer L2) {
	polypointer p, q, c, d;
	int x;
	p = L1->link;
	q = L2->link;
	c = new polynode;
	c->link = NULL;
	d = c;
	while ((p != NULL) && (q != NULL))
	{
		if (p->exp == q->exp)
		{
			x = p->coef - q->coef;
			if (x != 0)
				Attach(x, p->exp, d);
			p = p->link;
			q = q->link;
		}
		else if (p->exp > q->exp)
		{
			Attach(p->coef, p->exp, d);
			p = p->link;
		}
		else if (p->exp < q->exp)
		{
			int m = q->coef * (-1);
			Attach(m, q->exp, d);
			q = q->link;
		}
	}
	while (p != NULL)
	{
		Attach(p->coef, p->exp, d);
		p = p->link;
	}
	while (q != NULL)
	{
		Attach(q->coef * (-1), q->exp, d);
		q = q->link;
	}
	return c;
}

//排序与合并操作
polypointer Sort(polypointer& L)
{
	int temp1, temp2;
	polypointer r = NULL;
	bool isChange = true;
	while (r != L->link->link && isChange)
	{
		polypointer q = L->link;
		isChange = false; //标志当前这一轮中又没有发生元素交换，如果没有则表示数组已经有序
		for (; q->link && q->link != r; q = q->link)
			if (q->exp < q->link->exp) {
				temp1 = q->exp;
				q->exp = q->link->exp;
				q->link->exp = temp1;

				temp2 = q->coef;
				q->coef = q->link->coef;
				q->link->coef = temp2;
				isChange = true;
			}
		r = q;
	}
	return L;
}
void SameUnit(polypointer& L)
{
	polypointer r, h;
	r = L->link;
	while (r->link != NULL)
	{
		if (r->exp == r->link->exp) {
			r->coef = r->link->coef + r->coef;
			h = r->link;
			r->link = r->link->link;
			delete h;
		}
		r = r->link;
	}
}
//乘法函数，乘法的算法：1、以暴力的方式先做拆括号运算，每一项是系数相乘指数相加，连到新表之后  2、以指数做冒泡排序，之后遍历检测后做合并同类项操作。
polypointer PolyMultiply(polypointer L1, polypointer L2)
{
	polypointer p, q, c, d;
	int x, y;

	c = new polynode;
	c->link = NULL;
	d = c;
	for (p = L1->link; p != NULL; p = p->link) {
		for (q = L2->link; q != NULL; q = q->link) {
			x = p->coef * q->coef;
			y = p->exp + q->exp;
			Attach(x, y, d);
		}
	}
	Sort(c);
	SameUnit(c);
	return c;
}

//除法的算法（默认第一个多项式最高指数大于第二个）：（带余除法）
	//1、参考多项式大除法的方式，一位一位地算商式，并链接到商式链表最后
	//2、每操作一次：新的被除式 = 原被除式—（除式 * 这一位的商式）
	//3、迭代该除法操作，当被除式的最高次小于除式的最高次时产生余项。
void PolyDivide(polypointer& L3, polypointer& L4, polypointer& L1/*被除式*/, polypointer& L2/*除式*/)
{
	polypointer r, s, t;
	r = L1->link;
	s = L2->link;
	int c, e;
	c = r->coef / s->coef;
	e = r->exp - s->exp;
	t = L3;
	while (t->link != NULL)
		t = t->link;
	Attach(c, e, t);

	polypointer temp = new polynode;
	temp->link = NULL;
	polypointer a = temp;
	Attach(c, e, a);

	polypointer temp2 = PolyMultiply(L2, temp);
	L1 = PolyMinus(L1, temp2);
	if (L1->link == NULL || L1->link->exp < L2->link->exp) {
		L4 = L1;
		return;
	}
	PolyDivide(L3, L4, L1, L2);
}

//执行除法的先决条件，即将系数为0的项补全
void Insert0(polypointer p, polypointer& L)
{
	polypointer q;
	q = new polynode;
	q->coef = 0;
	q->exp = p->exp - 1;
	q->link = p->link;
	p->link = q;
}
void MakeFull(polypointer& L1)
{
	polypointer p;
	for (p = L1->link; p->link != NULL; p = p->link) {
		if (p->exp != p->link->exp + 1)
			Insert0(p, L1);
	}
	while (p->exp != 0)
	{
		Attach(0, p->exp - 1, p);
	}

}

//输出链表存储的多项式
void Print(polypointer& L) {
	polypointer p = L->link;
	if (p == NULL) {
		cout << 0;
	}
	while (p != NULL) {
		if (p->exp != 0) {
			cout << p->coef << "x^" << p->exp;
		}
		else {
			cout << p->coef;
		}
		p = p->link;
		if (p == NULL) {
			break;
		}
		else if (p->coef > 0) {
			cout << "+";
		}
	}
	cout << endl;
}

//释放申请的空间
void destoryPoly(polypointer& q) {
	polypointer node = q;
	while (node != NULL) {
		node = node->link;  //p指向下一个待销毁的结点
		delete q;  //销毁当前结点
		q = node;   //
	}
}

//申请存储两个多项式的空间，并调用算术函数
void minorMain(int a) {
	polypointer L1, L2;
	L1 = new polynode;
	L1->link = NULL;
	L2 = new polynode;
	L2->link = NULL;

	Input(L1);          //输入单链表L1
	cout << "f(x)=";
	Print(L1);         //输出单链表L1

	Input(L2);         //输入单链表L2
	cout << "g(x)=";
	Print(L2);         //输出单链表L2

	switch (a)
	{
	case 1: {
		polypointer L0;
		L0 = PolyAdd(L1, L2);          //调用加法函数
		cout << "F(x)=f(x)+g(x)=";
		Print(L0);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L0);
		break;
	}

	case 2: {
		polypointer L9;
		L9 = PolyMinus(L1, L2);          //调用减法函数
		cout << "F(x)=f(x)-g(x)=";
		Print(L9);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L9);
		break;
	}

	case 3: {
		polypointer L8;
		L8 = PolyMultiply(L1, L2);         //调用乘法法函数
		cout << "F(x)=f(x)*g(x)=";
		Print(L8);
		destoryPoly(L1);
		destoryPoly(L2);
		destoryPoly(L8);
		break;
	}

	case 4: {
		MakeFull(L1);
		MakeFull(L2);
		polypointer L3, L4;
		L3 = new polynode;
		L3->link = NULL;
		L4 = new polynode;
		L4->link = NULL;
		PolyDivide(L3, L4, L1, L2);              //调用递归除法函数
		cout << "F(x)=f(x)/g(x):" << endl;
		cout << "商式: ";
		Print(L3);
		cout << endl;
		cout << "余式: ";
		Print(L4);
		break;
	}
	}
}

int main()
{
	cout << "0.退出" << endl;
	cout << "1.两个一元多项式相加" << endl;
	cout << "2.两个一元多项式相减" << endl;
	cout << "3.两个一元多项式相乘" << endl;
	cout << "4.两个一元多项式相除" << endl;
	int a;
	while (1) {                //循环程序，直到输入0
		cout << "请选择操作：";
		cin >> a;
		if (a == 1) {
			cout << "你选择的操作是多项式相加：" << endl;
			minorMain(a);
		}
		else if (a == 2) {
			cout << "你选择的操作是多项式相减：" << endl;
			minorMain(a);
		}
		else if (a == 3) {
			cout << "你选择的操作是多项式相乘：" << endl;
			minorMain(a);
		}
		else if (a == 4) {
			cout << "你选择的操作是多项式相除：" << endl;
			minorMain(a);
		}
		else if (a == 0) {
			break;
		}
		else {
			cout << "输入错误！" << endl;
		}
	}
}