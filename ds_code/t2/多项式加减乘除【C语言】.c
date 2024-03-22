#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LNode {
	int coef;
	int expon;
	struct LNode* next;
} LNode, * PolyLink;

void PolyCreate(PolyLink* p) {   // p为指针的指针 为了修改指针 
	int n;    // 输入多项式有n项
	PolyLink s; // 输入多项式节点
	printf("Please Input the Number of Polynomial: ");
	scanf("%d", &n);     // 读入项的数量
	printf("Please Input the expon: \n");
	for (n; n > 0; n--) {   // 读入系数 并且插入节点
		s = (PolyLink)malloc(sizeof(LNode));
		if (s == NULL) {
			printf("%s","Failed to allocate memory.");
			system("pause");
			exit(1);    //解决对NULL指针的引用方法
		}
		printf("Input the coef: ");
		scanf("%d", &(s->coef));
		printf("Input the expon: ");
		scanf("%d", &(s->expon));
		s->next = (*p)->next;
		(*p)->next = s;
	}
}

void PolyPrint(PolyLink p) {
	PolyLink q = p->next;
	if (q == NULL) {                           // 为0
		printf("0");
	}
	else {
		if (q->expon == 0) {                   //先打印最高项
			printf("%d", q->coef);
		}
		else {
			printf("%d*x^%d", q->coef, q->expon);
		}
		q = q->next;
		while (q != NULL) {                 // 打印后面的项
			if (q->coef > 0) {              // 系数为正 打印+
				if (q->expon == 0) {
					printf("+%df", q->coef);
				}
				else {
					printf("+%d*x^%d", q->coef, q->expon);
				}
			}
			else if (q->coef < 0) {          // 系数为负 不打印+
				if (q->expon == 0) {
					printf("%d", q->coef);
				}
				else {
					printf("%d*x^%d", q->coef, q->expon);
				}
			}
			else;                            // 系数为0 跳过 不打印
			q = q->next;
		}
	}
}

int Campare(int a, int b) {  // 比较a b大小
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

void Delete(PolyLink* p, PolyLink q) {    //删除q元素
	(*p)->next = q->next;
	free(q);
}

void Insert(PolyLink* p, PolyLink q) {   //插入q元素
	q->next = (*p)->next;
	(*p)->next = q;
}

void Append(PolyLink* p, PolyLink q) {  // 将链表q插入 尾部插入
	PolyLink s, tail = (*p);
	while (q) {
		s = (PolyLink)malloc(sizeof(LNode));
		if (s == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //解决对NULL指针的引用方法
		}
		s->coef = q->coef;
		s->expon = q->expon;
		s->next = NULL;
		tail->next = s;
		tail = s;
		q = q->next;
	}
}

void Destory(PolyLink* p) {    // 删除*p
	while ((*p)->next) {
		Delete(p, (*p)->next);
	}
	free(*p);
}

PolyLink GetMax(PolyLink p) {   // 得到最高项
	PolyLink q = p->next;
	if (q) {
		while (q->next) {
			q = q->next;
		}
	}
	else {
		return 0;
	}
	return q;
}

void PolyAdd(PolyLink* p1, PolyLink p2) {  // p1+p2 结果返回放到p1
	PolyLink qa = (*p1)->next, ha = *p1; // ha为qa的前驱节点
	PolyLink qb = p2->next, hb;          // hb为qb的前驱节点
	int expona, exponb;
	while (qa && qb) {
		expona = qa->expon;
		exponb = qb->expon;
		switch (Campare(expona, exponb)) {
		case -1:       // expona < exponb
			ha = qa;
			qa = qa->next;
			break;
		case 0:        // 二者相等
			qa->coef += qb->coef;
			if (qa->coef) {   // 若系数和为0 则删除节点 不为零则保存
				ha = qa;
			}
			else {
				Delete(&ha, qa);
			}
			qa = ha->next;
			qb = qb->next;
			break;
		case 1:     // 如果此时qa大于qb 就在qa前也就是ha后插入此时的qb
			hb = (PolyLink)malloc(sizeof(LNode));
			if (hb == NULL) {
				printf("%s", "Failed to allocate memory.");
				system("pause");
				exit(1);    //解决对NULL指针的引用方法
			}
			hb->coef = qb->coef;
			hb->expon = qb->expon;
			Insert(&ha, hb);
			qb = qb->next;
			ha = ha->next;
			break;
		}
	}
	if (qb) {        // 如果此时qa先没了，那么就把qb后面的都链接到qa后面，最后返回qa
		Append(&ha, qb);
	}
}

void PolySub(PolyLink* p1, PolyLink p2) {  // p1-p2 结果返回放到p1
	PolyLink qa = (*p1)->next, ha = *p1; // ha为qa的前驱节点
	PolyLink qb = p2->next, hb;          // hb为qb的前驱节点
	int expona, exponb;
	while (qa && qb) {
		expona = qa->expon;
		exponb = qb->expon;
		switch (Campare(expona, exponb)) {
		case -1:       // expona < exponb
			ha = qa;
			qa = qa->next;
			break;
		case 0:        // 二者相等
			qa->coef -= qb->coef;
			if (qa->coef) {   // 若系数和为0 则删除节点 不为零则保存
				ha = qa;
			}
			else {
				Delete(&ha, qa);
			}
			qa = ha->next;
			qb = qb->next;
			break;
		case 1:     // 如果此时qa大于qb 就在qa前也就是ha后插入此时的qb
			hb = (PolyLink)malloc(sizeof(LNode));
			if (hb == NULL) {
				printf("%s", "Failed to allocate memory.");
				system("pause");
				exit(1);    //解决对NULL指针的引用方法
			}
			hb->coef = -1 * qb->coef;
			hb->expon = qb->expon;
			Insert(&ha, hb);
			qb = qb->next;
			ha = ha->next;
			break;
		}
	}
	if (qb) {        // 如果此时qa先没了，那么就把qb后面的都链接到qa后面，最后返回qa
		Append(&ha, qb);
		ha = ha->next;
		while (ha) {
			ha->coef *= -1;
			ha = ha->next;
		}
	}
}

void PolyMul(PolyLink* p1, PolyLink p2) {
	PolyLink temp, res, qa, qb = p2->next;
	res = (PolyLink)malloc(sizeof(LNode));
	if (res == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //解决对NULL指针的引用方法
	}
	res->coef = res->expon = 0;
	res->next = NULL;
	while (qb) {         // 先用p2的第一项乘p1的每一项，以此类推
		temp = (PolyLink)malloc(sizeof(LNode));
		if (temp == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //解决对NULL指针的引用方法
		}
		temp->coef = temp->expon = 0;
		temp->next = NULL;
		PolyAdd(&temp, *p1);   // 把p1复制temp里 防止下面不小心修改p1
		qa = temp->next;       // 并且用temp暂存每一次的结果
		while (qa) {
			qa->coef *= qb->coef;
			qa->expon += qb->expon;
			qa = qa->next;    // p1每一项都去乘p2的第一项 也就是qb 此时暂存在temp里
		}
		PolyAdd(&res, temp);  // 将此时的结果复制到res里
		Destory(&temp);       // 结果已放到res里，故清空temp，以存放下次结果
		qb = qb->next;        // 用p2的下一项去分别乘p1的每一项
	}
	*p1 = res;
}

void PolyDev(PolyLink* p1, PolyLink* p2) {   // 两多项式相除 p1÷p2，返回的p1为商，p2为余多项式
	PolyLink res, temp1, temp2, q;           // res用来存放结果，temp1存放余多项式，temp2存放每一次除法的商
	res = (PolyLink)malloc(sizeof(LNode));
	if (res == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //解决对NULL指针的引用方法
	}
	res->coef = res->expon = 0; res->next = NULL; // 初始化res
	while (GetMax(*p1) && GetMax(*p1)->expon >= GetMax(*p2)->expon) { // p1 p2 存在最高项 即不是0
		temp2 = (PolyLink)malloc(sizeof(LNode));
		if (temp2 == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //解决对NULL指针的引用方法
		}
		temp1 = (PolyLink)malloc(sizeof(LNode));
		if (temp1 == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //解决对NULL指针的引用方法
		}
		temp1->coef = temp1->expon = 0; temp1->next = NULL;  // 初始化temp1
		temp2->coef = (GetMax(*p1)->coef) / (GetMax(*p2)->coef);
		temp2->expon = (GetMax(*p1)->expon) - (GetMax(*p2)->expon);   // 得到商多项式的第一个节点
		PolyAdd(&temp1, *p2);   // 把p2复制到temp1里，整个运算期间p2和temp1是不变的
		q = temp1->next;       // 指向temp1第一个元素
		Insert(&res, temp2);   // 将商的节点多项式插入到结果中，temp2只是个节点，所以用Insert函数
		while (q) {            // 令temp1也就是p2与商节点也就是temp2相乘，p1减去得到的结果即为新的p1，被除多项式更新
			q->coef *= temp2->coef;
			q->expon += temp2->expon;
			q = q->next;
		}
		PolySub(p1, temp1);     // 此处得到的差多项式作为更新之后的p1
		Destory(&temp1);        // 释放temp1
	}
	temp1 = *p1;  // 暂存*p1 实际上此时得到的*p1是余多项式
	*p1 = res;
	*p2 = temp1;
}

int main(void) {
	PolyLink p1 = (PolyLink)malloc(sizeof(PolyLink));
	if (p1 == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //解决对NULL指针的引用方法
	}
	PolyLink p2 = (PolyLink)malloc(sizeof(PolyLink));
	if (p2 == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //解决对NULL指针的引用方法
	}
	p1->next = p2->next = NULL;    // 初始化
	p1->coef = p2->coef = 0;
	p1->expon = p2->expon = 0;

	printf("Start Poly1\n");
	PolyCreate(&p1);
	PolyPrint(p1);

	printf("\nStart Poly2\n");
	PolyCreate(&p2);
	PolyPrint(p2);

	//PolyMul(&p1, p2);
	//PolyAdd(&p1, p2);
	//PolySub(&p1, p2);
	PolyDev(&p1, &p2);
	printf("\nAfter Calculating...\n");
	PolyPrint(p1);

	Destory(&p1);
	Destory(&p2);
	return 0;
}
