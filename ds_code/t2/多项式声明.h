typedef struct term {
    float coef; //ϵ��
    int expn;   //ָ��
    struct term* next;
}Poly,*Link;

int LocateElem(Link p, Link s, Link& q); //��λ����
void CreatePolyn(Link& p, int m);        //��������ʽ
void PrintPolyn(Link p);                 //��ӡ����ʽ����ʾ��
int cmp(Link a, Link b);                 //�Ƚ���ߴ���
Link AddPolyn(Link pa, Link pb);         //����ʽ���
Link SubPolyn(Link pa, Link pb);         //����ʽ���
Link Reverse(Link p);                    //���ö���ʽ
Link MultiplyPolyn(Link A, Link B);      //����ʽ���
void Calculate(Link p, float x);         //����ʽ��ֵ