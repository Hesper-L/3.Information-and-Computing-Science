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

void PolyCreate(PolyLink* p) {   // pΪָ���ָ�� Ϊ���޸�ָ�� 
	int n;    // �������ʽ��n��
	PolyLink s; // �������ʽ�ڵ�
	printf("Please Input the Number of Polynomial: ");
	scanf("%d", &n);     // �����������
	printf("Please Input the expon: \n");
	for (n; n > 0; n--) {   // ����ϵ�� ���Ҳ���ڵ�
		s = (PolyLink)malloc(sizeof(LNode));
		if (s == NULL) {
			printf("%s","Failed to allocate memory.");
			system("pause");
			exit(1);    //�����NULLָ������÷���
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
	if (q == NULL) {                           // Ϊ0
		printf("0");
	}
	else {
		if (q->expon == 0) {                   //�ȴ�ӡ�����
			printf("%d", q->coef);
		}
		else {
			printf("%d*x^%d", q->coef, q->expon);
		}
		q = q->next;
		while (q != NULL) {                 // ��ӡ�������
			if (q->coef > 0) {              // ϵ��Ϊ�� ��ӡ+
				if (q->expon == 0) {
					printf("+%df", q->coef);
				}
				else {
					printf("+%d*x^%d", q->coef, q->expon);
				}
			}
			else if (q->coef < 0) {          // ϵ��Ϊ�� ����ӡ+
				if (q->expon == 0) {
					printf("%d", q->coef);
				}
				else {
					printf("%d*x^%d", q->coef, q->expon);
				}
			}
			else;                            // ϵ��Ϊ0 ���� ����ӡ
			q = q->next;
		}
	}
}

int Campare(int a, int b) {  // �Ƚ�a b��С
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

void Delete(PolyLink* p, PolyLink q) {    //ɾ��qԪ��
	(*p)->next = q->next;
	free(q);
}

void Insert(PolyLink* p, PolyLink q) {   //����qԪ��
	q->next = (*p)->next;
	(*p)->next = q;
}

void Append(PolyLink* p, PolyLink q) {  // ������q���� β������
	PolyLink s, tail = (*p);
	while (q) {
		s = (PolyLink)malloc(sizeof(LNode));
		if (s == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //�����NULLָ������÷���
		}
		s->coef = q->coef;
		s->expon = q->expon;
		s->next = NULL;
		tail->next = s;
		tail = s;
		q = q->next;
	}
}

void Destory(PolyLink* p) {    // ɾ��*p
	while ((*p)->next) {
		Delete(p, (*p)->next);
	}
	free(*p);
}

PolyLink GetMax(PolyLink p) {   // �õ������
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

void PolyAdd(PolyLink* p1, PolyLink p2) {  // p1+p2 ������طŵ�p1
	PolyLink qa = (*p1)->next, ha = *p1; // haΪqa��ǰ���ڵ�
	PolyLink qb = p2->next, hb;          // hbΪqb��ǰ���ڵ�
	int expona, exponb;
	while (qa && qb) {
		expona = qa->expon;
		exponb = qb->expon;
		switch (Campare(expona, exponb)) {
		case -1:       // expona < exponb
			ha = qa;
			qa = qa->next;
			break;
		case 0:        // �������
			qa->coef += qb->coef;
			if (qa->coef) {   // ��ϵ����Ϊ0 ��ɾ���ڵ� ��Ϊ���򱣴�
				ha = qa;
			}
			else {
				Delete(&ha, qa);
			}
			qa = ha->next;
			qb = qb->next;
			break;
		case 1:     // �����ʱqa����qb ����qaǰҲ����ha������ʱ��qb
			hb = (PolyLink)malloc(sizeof(LNode));
			if (hb == NULL) {
				printf("%s", "Failed to allocate memory.");
				system("pause");
				exit(1);    //�����NULLָ������÷���
			}
			hb->coef = qb->coef;
			hb->expon = qb->expon;
			Insert(&ha, hb);
			qb = qb->next;
			ha = ha->next;
			break;
		}
	}
	if (qb) {        // �����ʱqa��û�ˣ���ô�Ͱ�qb����Ķ����ӵ�qa���棬��󷵻�qa
		Append(&ha, qb);
	}
}

void PolySub(PolyLink* p1, PolyLink p2) {  // p1-p2 ������طŵ�p1
	PolyLink qa = (*p1)->next, ha = *p1; // haΪqa��ǰ���ڵ�
	PolyLink qb = p2->next, hb;          // hbΪqb��ǰ���ڵ�
	int expona, exponb;
	while (qa && qb) {
		expona = qa->expon;
		exponb = qb->expon;
		switch (Campare(expona, exponb)) {
		case -1:       // expona < exponb
			ha = qa;
			qa = qa->next;
			break;
		case 0:        // �������
			qa->coef -= qb->coef;
			if (qa->coef) {   // ��ϵ����Ϊ0 ��ɾ���ڵ� ��Ϊ���򱣴�
				ha = qa;
			}
			else {
				Delete(&ha, qa);
			}
			qa = ha->next;
			qb = qb->next;
			break;
		case 1:     // �����ʱqa����qb ����qaǰҲ����ha������ʱ��qb
			hb = (PolyLink)malloc(sizeof(LNode));
			if (hb == NULL) {
				printf("%s", "Failed to allocate memory.");
				system("pause");
				exit(1);    //�����NULLָ������÷���
			}
			hb->coef = -1 * qb->coef;
			hb->expon = qb->expon;
			Insert(&ha, hb);
			qb = qb->next;
			ha = ha->next;
			break;
		}
	}
	if (qb) {        // �����ʱqa��û�ˣ���ô�Ͱ�qb����Ķ����ӵ�qa���棬��󷵻�qa
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
		exit(1);    //�����NULLָ������÷���
	}
	res->coef = res->expon = 0;
	res->next = NULL;
	while (qb) {         // ����p2�ĵ�һ���p1��ÿһ��Դ�����
		temp = (PolyLink)malloc(sizeof(LNode));
		if (temp == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //�����NULLָ������÷���
		}
		temp->coef = temp->expon = 0;
		temp->next = NULL;
		PolyAdd(&temp, *p1);   // ��p1����temp�� ��ֹ���治С���޸�p1
		qa = temp->next;       // ������temp�ݴ�ÿһ�εĽ��
		while (qa) {
			qa->coef *= qb->coef;
			qa->expon += qb->expon;
			qa = qa->next;    // p1ÿһ�ȥ��p2�ĵ�һ�� Ҳ����qb ��ʱ�ݴ���temp��
		}
		PolyAdd(&res, temp);  // ����ʱ�Ľ�����Ƶ�res��
		Destory(&temp);       // ����ѷŵ�res������temp���Դ���´ν��
		qb = qb->next;        // ��p2����һ��ȥ�ֱ��p1��ÿһ��
	}
	*p1 = res;
}

void PolyDev(PolyLink* p1, PolyLink* p2) {   // ������ʽ��� p1��p2�����ص�p1Ϊ�̣�p2Ϊ�����ʽ
	PolyLink res, temp1, temp2, q;           // res������Ž����temp1��������ʽ��temp2���ÿһ�γ�������
	res = (PolyLink)malloc(sizeof(LNode));
	if (res == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //�����NULLָ������÷���
	}
	res->coef = res->expon = 0; res->next = NULL; // ��ʼ��res
	while (GetMax(*p1) && GetMax(*p1)->expon >= GetMax(*p2)->expon) { // p1 p2 ��������� ������0
		temp2 = (PolyLink)malloc(sizeof(LNode));
		if (temp2 == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //�����NULLָ������÷���
		}
		temp1 = (PolyLink)malloc(sizeof(LNode));
		if (temp1 == NULL) {
			printf("%s", "Failed to allocate memory.");
			system("pause");
			exit(1);    //�����NULLָ������÷���
		}
		temp1->coef = temp1->expon = 0; temp1->next = NULL;  // ��ʼ��temp1
		temp2->coef = (GetMax(*p1)->coef) / (GetMax(*p2)->coef);
		temp2->expon = (GetMax(*p1)->expon) - (GetMax(*p2)->expon);   // �õ��̶���ʽ�ĵ�һ���ڵ�
		PolyAdd(&temp1, *p2);   // ��p2���Ƶ�temp1����������ڼ�p2��temp1�ǲ����
		q = temp1->next;       // ָ��temp1��һ��Ԫ��
		Insert(&res, temp2);   // ���̵Ľڵ����ʽ���뵽����У�temp2ֻ�Ǹ��ڵ㣬������Insert����
		while (q) {            // ��temp1Ҳ����p2���̽ڵ�Ҳ����temp2��ˣ�p1��ȥ�õ��Ľ����Ϊ�µ�p1����������ʽ����
			q->coef *= temp2->coef;
			q->expon += temp2->expon;
			q = q->next;
		}
		PolySub(p1, temp1);     // �˴��õ��Ĳ����ʽ��Ϊ����֮���p1
		Destory(&temp1);        // �ͷ�temp1
	}
	temp1 = *p1;  // �ݴ�*p1 ʵ���ϴ�ʱ�õ���*p1�������ʽ
	*p1 = res;
	*p2 = temp1;
}

int main(void) {
	PolyLink p1 = (PolyLink)malloc(sizeof(PolyLink));
	if (p1 == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //�����NULLָ������÷���
	}
	PolyLink p2 = (PolyLink)malloc(sizeof(PolyLink));
	if (p2 == NULL) {
		printf("%s", "Failed to allocate memory.");
		system("pause");
		exit(1);    //�����NULLָ������÷���
	}
	p1->next = p2->next = NULL;    // ��ʼ��
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
